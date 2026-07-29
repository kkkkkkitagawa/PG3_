#include <condition_variable>
#include <functional>
#include <iostream>
#include <latch>
#include <mutex>
#include <thread>

constexpr int kThreadCount = 3;

struct PrintOrder
{
    std::mutex mutex;
    std::condition_variable condition;
    int nextThreadNumber = 1;
};

void PrintThread(
    const int threadNumber,
    std::latch& startSignal,
    PrintOrder& printOrder)
{
    // Wait until all three worker threads have been created.
    startSignal.arrive_and_wait();

    std::unique_lock lock(printOrder.mutex);
    printOrder.condition.wait(
        lock,
        [&printOrder, threadNumber]()
        {
            return printOrder.nextThreadNumber == threadNumber;
        });

    std::cout << "thread " << threadNumber << '\n';
    ++printOrder.nextThreadNumber;

    lock.unlock();
    printOrder.condition.notify_all();
}

int main()
{
    std::latch startSignal(kThreadCount + 1);
    PrintOrder printOrder;

    std::thread thread1(PrintThread, 1, std::ref(startSignal), std::ref(printOrder));
    std::thread thread2(PrintThread, 2, std::ref(startSignal), std::ref(printOrder));
    std::thread thread3(PrintThread, 3, std::ref(startSignal), std::ref(printOrder));

    startSignal.arrive_and_wait();

    thread1.join();
    thread2.join();
    thread3.join();

    return 0;
}
