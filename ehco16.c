#include "stdio.h"
int main()
{
    double sum=1;
    int sign=1;
    for(double i=2;i<=100;sum=sum-(1/i)*sign,i++,sign=-sign);
    printf("result is %g\n",sum);
    system("pause");
    return 0;
}