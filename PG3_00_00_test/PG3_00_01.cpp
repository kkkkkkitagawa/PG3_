#include <chrono>
#include <functional>
#include <iostream>
#include <limits>
#include <random>
#include <thread>

#ifdef _WIN32
#include <Windows.h>
#endif

// 指定時間待ってから、受け取った関数を実行する。
void SetTimeout(const std::function<void()>& callback, int milliseconds)
{
	int remainingMilliseconds = milliseconds;

	while (remainingMilliseconds > 0) {
		const int waitTime =
			remainingMilliseconds >= 1000 ? 1000 : remainingMilliseconds;

		std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
		std::cout << "." << std::flush;
		remainingMilliseconds -= waitTime;
	}

	std::cout << "\n";
	callback();
}

int RollDice()
{
	static std::random_device randomDevice;
	static std::mt19937 randomEngine(randomDevice());
	std::uniform_int_distribution<int> dice(1, 6);

	return dice(randomEngine);
}

int GetUserAnswer()
{
	int answer = 0;

	while (true) {
		std::cout << "出目が「丁（偶数）」か「半（奇数）」かを予想してください。\n";
		std::cout << "半なら 1、丁なら 2 を入力: ";

		if (std::cin >> answer && (answer == 1 || answer == 2)) {
			return answer;
		}

		std::cout << "入力が正しくありません。1 または 2 を入力してください。\n\n";
		std::cin.clear();
		std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
	}
}

int main()
{
#ifdef _WIN32
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
#endif

	std::cout << "=== 丁半博打 ===\n\n";

	const int userAnswer = GetUserAnswer();
	const int diceResult = RollDice();

	std::cout << "\nサイコロを振りました。\n";
	std::cout << "結果は" << std::flush;

	// std::functionにラムダ式を代入する。
	std::function<void()> showResult = [userAnswer, diceResult]() {
		const bool isCho = diceResult % 2 == 0;
		const int correctAnswer = isCho ? 2 : 1;

		std::cout << "\nサイコロの出目は " << diceResult << " です。\n";
		std::cout << "結果は「" << (isCho ? "丁（偶数）" : "半（奇数）") << "」です。\n";

		if (userAnswer == correctAnswer) {
			std::cout << "正解です！\n";
		} else {
			std::cout << "不正解です。\n";
		}
	};

	SetTimeout(showResult, 3000);

	return 0;
}
