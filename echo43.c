#include "stdio.h"
void swap(int *p1,int *p2)
{
    int t;
    t=*p1;
    *p1=*p2;
    *p2=t;
}
int main()
{
    int a,b;
    int *p1,*p2;
    p1=&a;
    p2=&b;
    printf("Please enter the number you wanna swap\n");
    scanf("%d %d",&a,&b);
    swap(p1,p2);
    printf("%d %d\n",a,b);
    system("pause");
    return 0;
}