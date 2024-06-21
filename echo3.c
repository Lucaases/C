#include <stdio.h>
#include <math.h>
double main()
{
    double a,b,c;
    scanf("%lf,%lf",&a,&b);
    c = pow(a,b); 
    if (a=0) {
      printf("底数为0无法计算\n");
    } else {
        printf("result is %lf\n",c);
    }
    system("pause");
    return 0;
}
