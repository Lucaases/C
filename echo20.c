#include "stdio.h"
int main()
{
    int i,sum;
    int a[10]={1};
    for(i=0;i<=9;i++)
    {
        a[i+1]=(a[i]+1)*2;
    }
    printf("%d\t",a[9]);
    system("pause");
    return 0;
}