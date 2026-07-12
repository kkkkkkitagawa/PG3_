#include <iostream>
#include <chrono>
#include <thread>

class Enemy {
public:
    void Update();
    bool IsFinished() const;

private:
    enum class State {
        Approach,
        Shoot,
        Leave,
        Finished,
        Count,
    };

    using StateFunc = void (Enemy::*)();

    void Approach();
    void Shoot();
    void Leave();
    void Finished();
    void PrintTransitionDots() const;

    static StateFunc spFuncTable[static_cast<int>(State::Count)];

    State state_ = State::Approach;
};

Enemy::StateFunc Enemy::spFuncTable[static_cast<int>(Enemy::State::Count)] = {
    &Enemy::Approach,
    &Enemy::Shoot,
    &Enemy::Leave,
    &Enemy::Finished,
};

void Enemy::Update()
{
    StateFunc pFunc = spFuncTable[static_cast<int>(state_)];
    (this->*pFunc)();
}

bool Enemy::IsFinished() const
{
    return state_ == State::Finished;
}

void Enemy::PrintTransitionDots() const
{
    using namespace std::chrono_literals;

    for (int i = 0; i < 3; ++i) {
        std::this_thread::sleep_for(500ms);
        std::cout << "." << std::flush;
    }

    std::cout << "\n";
}

void Enemy::Approach()
{
    std::cout << "Enemy state: Approach\n";
    PrintTransitionDots();
    state_ = State::Shoot;
}

void Enemy::Shoot()
{
    std::cout << "Enemy state: Shoot\n";
    PrintTransitionDots();
    state_ = State::Leave;
}

void Enemy::Leave()
{
    std::cout << "Enemy state: Leave\n";
    state_ = State::Finished;
}

void Enemy::Finished()
{
    std::cout << "Enemy state: Finished\n";
}

int main()
{
    Enemy enemy;

    while (!enemy.IsFinished()) {
        enemy.Update();
    }
}
