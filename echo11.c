#include <stdio.h>
#include <stdlib.h>   // 引入 abs 函数

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int sum = a * a + b * b;
    int hundred_digit = (sum > 100) ? abs(sum) / 100 : -1;
    printf("%d\n", (hundred_digit != -1) ? hundred_digit : sum);
    system("pause");
    return 0;
}