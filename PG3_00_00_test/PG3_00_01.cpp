#include <chrono>
#include <iostream>
#include <limits>
#include <random>
#include <thread>

#ifdef _WIN32
#include <Windows.h>
#endif

// 判定結果を受け取る
using ResultCallback = void (*)(int);

void ShowCorrectResult(int diceResult)
{
	std::cout << "\nサイコロの出目は " << diceResult << " です。\n";
	std::cout << "正解\n";
}

void ShowIncorrectResult(int diceResult)
{
	std::cout << "\nサイコロの出目は " << diceResult << " です。\n";
	std::cout << "不正解\n";
}

// 関数呼び出す
void JudgeAnswer(
	int diceResult,
	int userAnswer,
	ResultCallback onCorrect,
	ResultCallback onIncorrect)
{
	const int correctAnswer = (diceResult % 2 == 0) ? 2 : 1;

	if (userAnswer == correctAnswer) {
		onCorrect(diceResult);
	} else {
		onIncorrect(diceResult);
	}
}

int GetUserAnswer()
{
	int answer = 0;

	while (true) {
		std::cout << "出目は奇数と偶数のどちらでしょう？\n";
		std::cout << "奇数なら 1、偶数なら 2 を入力してください: ";

		if (std::cin >> answer && (answer == 1 || answer == 2)) {
			return answer;
		}

		std::cout << "1 または 2 を入力してください。\n\n";
		std::cin.clear();
		std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
	}
}

int RollDice()
{
	std::random_device randomDevice;
	std::mt19937 randomEngine(randomDevice());
	std::uniform_int_distribution<int> dice(1, 6);
	return dice(randomEngine);
}

void WaitForResult()
{
	std::cout << "判定中";

	for (int i = 0; i < 3; ++i) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "." << std::flush;
	}
}

int main()
{
#ifdef _WIN32
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
#endif

	const int diceResult = RollDice();
	const int userAnswer = GetUserAnswer();

	WaitForResult();

	// コールバック
	JudgeAnswer(
		diceResult,
		userAnswer,
		ShowCorrectResult,
		ShowIncorrectResult);

	return 0;
}
