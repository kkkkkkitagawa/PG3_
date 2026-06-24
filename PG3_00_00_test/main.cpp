

#include <stdio.h>
#include <windows.h>

// 再帰的な賃金体系の時給計算関数
int RecursiveWage(int n) {
    if (n == 1) {
        return 100;
    }

    return RecursiveWage(n - 1) * 2 - 50;
}

int main() {
    // 文字化け
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int hour;
    int normalTotal = 0;
    int recursiveTotal = 0;

    printf("働く時間を入力してください：");
    scanf_s("%d", &hour);

    printf("\n計算結果\n");
    printf("------------------------------------------\n");
    printf("時間\t一般的な賃金体系\t再帰的な賃金体系\n");
    printf("------------------------------------------\n");

    for (int i = 1; i <= hour; i++) {
        normalTotal = 1072 * i;
        recursiveTotal += RecursiveWage(i);

        printf("%d時間\t%d円\t\t%d円\n", i, normalTotal, recursiveTotal);
    }

    printf("------------------------------------------\n");

    if (normalTotal < recursiveTotal) {
        printf("再帰的な賃金体系のほうが稼げます。\n");
    }
    else if (normalTotal > recursiveTotal) {
        printf("一般的な賃金体系のほうが稼げます。\n");
    }
    else {
        printf("同じ金額です。\n");
    }

    return 0;
}