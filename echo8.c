#include <stdio.h>

int main() {
    double a, b;
    printf("请输入两个整数：");
    scanf("%lf,%lf", &a, &b);
    
    printf("%lf + %lf = %g\n", a, b, a + b);
    printf("%lf - %lf = %g\n", a, b, a - b);
    printf("%lf * %lf = %g\n", a, b, a * b);
    if (b != 0) {
        printf("%lf / %lf = %g\n", a, b, a / b);
    } else {
        printf("除数为0，无法进行除法运算。\n");
    }
    system("pause");
    return 0;
}