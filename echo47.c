#include "stdio.h"
int array(int a[][4],int x,int y)
{
    int (*p)[4]=a;//二维指针,表示指向含有4个整型元素的一维数组
    printf("a[%d][%d]=%d\n",x,y,*(*(p+x)+y));
}

int main()
{
    int a[3][4]={0},b,c;
    int *p;
    for (p=a[0];p<a[0]+12;p++)
    {
       scanf("%d",p);
    }
    printf("%d %d\n",a,a[0]);//a为二维数组名
    printf("%d %d\n",*a,*(*a));//*a=a[0],*(*a)=a[0][0]
    printf("%d %d\n",a+1,a[1]+1);//a+1是第一行的所有元素地址,a[1]+1=*(a+1)+1,即a[1][1]的地址
    printf("%d %d\n",*(a+1)+1,*(*(a+1)+1));//*(a+1)+1=a[1]+1,即a[1][1]的地址,*(*(a+1)+1)=a[1][1]
    scanf("%d %d",&b,&c);
    array(a,b,c);
    system("pause");
    return 0;
}