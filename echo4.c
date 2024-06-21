#include <stdio.h>
#include <math.h>

int main() {
    double r,a;
    int n;
    int p=1;

    printf("请输入年增长率（%%）：");
    scanf("%lf", &r);

    printf("请输入年数（年）：");
    scanf("%d", &n);

    r = r / 100; 

    a = p * pow(1 + r, n); 

    printf("与现在相比的倍数为：%g\n", a);

    system("pause");

    return 0;
}
