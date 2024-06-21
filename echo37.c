#include "stdio.h"
int one(int a[],int n)
{
    int temp=a[0];
    a[0]=a[1];
    a[1]=temp;
}

int main()
{
    int a[4]={1,2,3,4};
    one(a,4);
    printf("The value of a before change is: %d\n", a[0]);
    one(a,4);
    printf("The value of a after change is: %d\n", a[0]);
    system("pause");
}