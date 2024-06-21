#include "stdio.h"
int Diagonal(int a[][4],int n)
{
    int sum1=0,sum2=0,sum=0,i,j;
    for(i=0;i<n;i++){
        for (j=0;j<n;j++)
        {
            if(i==j)
            {sum1+=a[i][j];}
            else if(i+j==n-1)
            {sum2+=a[i][j];}
        } 
    }
        sum=sum1+sum2;
        return sum;
}
int main()
{
    int a[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    printf("%d",Diagonal(a,4));
    system("pause");
}