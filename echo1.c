#include <stdio.h>
int main()
{
    int a,b,c,max;
    printf("请输入a,b,c的值");
    scanf("%d,%d,%d",&a,&b,&c);
    max = (a>b) ? a:b;
    max = (max>c) ? max:c;
    printf("三个数中的最大值= %d\n",max);
    system("pause");
    return 0;
}