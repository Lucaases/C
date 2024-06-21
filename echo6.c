#include <stdio.h>
#include <math.h>
int main()
{
    double a,c,d,f,g;
    int p=1000;
    int b;
    printf("请输入存款利息\n");
    scanf("%lf",&a);

    printf("请输入存款年限\n");
    scanf("%d",&b);

    c = a/100;
    d = p * pow(1+a,b);
    f = p * (1+a*b);
    g = p * pow(1+a/4,b*4);

    printf("d=%f\n,f=%f\n,g=%f\n",d,f,g);

    system("pause");

    return 0;
}


    


