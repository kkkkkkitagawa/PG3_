#include <chrono>
#include <iostream>
#include <string>
#include <utility>

int main()
{
    // 1,000,000文字の'a'で初期化された文字列を作成
    std::string a(1000000, 'a');

    // 文字列aをコピーし、処理にかかった時間を計測
    const auto copyStart = std::chrono::high_resolution_clock::now();
    std::string b = a;
    const auto copyEnd = std::chrono::high_resolution_clock::now();

    const auto copyTime =
        std::chrono::duration_cast<std::chrono::microseconds>(copyEnd - copyStart);

    // std::moveでaを右辺値にキャストして移動し、処理時間を計測
    const auto moveStart = std::chrono::high_resolution_clock::now();
    std::string c = std::move(a);
    const auto moveEnd = std::chrono::high_resolution_clock::now();

    const auto moveTime =
        std::chrono::duration_cast<std::chrono::microseconds>(moveEnd - moveStart);

    std::cout << "1,000,000文字のstd::stringをコピーと移動で比較しました。\n";
    std::cout << "コピー: " << copyTime.count() << " us\n";
    std::cout << "移動  : " << moveTime.count() << " us\n";
    std::cout << "コピー後の文字数: " << b.size() << '\n';
    std::cout << "移動後の文字数  : " << c.size() << '\n';

    return 0;
}
