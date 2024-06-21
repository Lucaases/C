#include "stdio.h"
void reverse1(int (*a)[3],int (*b)[3])//指向数组的指针变量
{
     int t,i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
           b[j][i] = a[i][j];
        }
    }
}
void reverse2(int *a,int *b)//指向数组元素的指针变量,注意形参为指向一维数组的指针变量
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
             *(b+3*j+i) = *(a+3*i+j);
        }
    }
}
int main()
{
    int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int b[3][3]={0};
    int *p;
    reverse1(a,b);
      for(p=*b;p<*b+9;p++)
    {if((p-*b)%3==0) printf("\n");
       printf("%4d",*p);
    }
    printf("\n");
    reverse2(*a,*b);//将二维数组转化成一维数组,确保数组名类型与形参类型相同
      for(p=*b;p<*b+9;p++)
    {if((p-*b)%3==0) printf("\n");
       printf("%4d",*p);
    } 
    system("pause"); 
    return 0;
}