#include <stdio.h>
#include "math.h"
int main()
{    
    int n,k,i,m=0;       
    for (n=51;n<=100;n+=2) {    
       k=sqrt(n);
       for(i=2;i<=k;i++)
       if(n%i==0)break;
       if(i>=k+1)
       {
        printf("%4d",n);
        m=m+1;
       }
    if (m%10==0) {    
        printf("\n");    
    }
    }
    printf("\n");
    system("pause");    
    return 0;    
}