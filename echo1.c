#include <stdio.h>
int main()
{
    int a,b,c,max;
    printf("������a,b,c��ֵ");
    scanf("%d,%d,%d",&a,&b,&c);
    max = (a>b) ? a:b;
    max = (max>c) ? max:c;
    printf("�������е����ֵ= %d\n",max);
    system("pause");
    return 0;
}