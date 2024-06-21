#include <stdio.h>
int main()
{
    double r,s;
    const double pi = 3.1415;
    printf("请输入r的值\n");
    scanf("%lf",&r);
    s = pi * r * r;
    printf("圆的面积为%g\n",s);
    return 0;
}

