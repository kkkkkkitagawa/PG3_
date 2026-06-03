#include <cstdio>
#include <windows.h>
#include <stdio.h>
// 関数テンプレート
template <typename Type>
Type Min(Type a, Type b) {
    return (a < b) ? a : b;
}

// char型の特殊化
template <>
char Min<char>(char a, char b) {
    printf("数字以外は代入できません\n");
    return (a < b) ? a : b;
}

int main() {
    int i1 = 10;
    int i2 = 20;

    float f1 = 3.141592f;
    float f2 = 3.711111f;

    double d1 = 8.88;
    double d2 = 9.99;

    char c1 = 'Z';
    char c2 = 'A';

    printf("int型の最小値: %d\n", Min(i1, i2));
    printf("float型の最小値: %f\n", Min(f1, f2));
    printf("double型の最小値: %lf\n", Min(d1, d2));
    printf("char型の最小値: %c\n", Min(c1, c2));

    return 0;
}
