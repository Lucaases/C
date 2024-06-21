#include "stdio.h"
int main()
{
    int a[4][4]={{1, 2, 3, 4},    
                {5, 6, 7, 8},    
                {9, 10, 11, 12},    
                {13, 14, 15, 16}};
    int i,j,m,n,column1,row1,max,min,column2,row2,sum;
    for(m=0;m<4;m++){
        for(n=0;n<4;n++)
        {
            scanf("%d",&a[m][n]);
        }
    }        
    max=a[0][0];
    min=a[0][0];
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[i][j]>a[0][0])
            {
                max=a[i][j];
                row1 = i+1;
                column1 = j+1;
            }
            if(a[i][j]<a[0][0])
            {
                min=a[i][j];
                row2 = i+1;
                column2 = j+1;
            }
        }    
    }
    sum=a[0][1]+a[1][1]+a[2][2]+a[3][3]+a[0][3]+a[1][2]+a[2][1]+a[3][0];
    printf("max=%d,row1=%d,column1=%d,min=%d,row2=%d,column2=%d,sum=%d\n",max,row1,column1,min,row2,column2,sum);
    system("pause");
    return 0;
}