#include <stdio.h>

// 再帰的な賃金体系の時給計算関数
int RecursiveWage(int n) {
    if (n == 1) {
        return 100;
    }

    return RecursiveWage(n - 1) * 2 - 50;
}

int main() {
    int hour;
    int normalTotal;
    int recursiveTotal = 0;

    printf("働く時間を入力してください：");
    scanf_s("%d", &hour);

    // 一般的な賃金体系の合計
    normalTotal = 1072 * hour;

    // 再帰的な賃金体系の合計
    for (int i = 1; i <= hour; i++) {
        recursiveTotal += RecursiveWage(i);
    }

    printf("\n%d時間働いた場合\n", hour);
    printf("一般的な賃金体系：%d円\n", normalTotal);
    printf("再帰的な賃金体系：%d円\n", recursiveTotal);

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