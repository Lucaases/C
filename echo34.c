#include "stdio.h"
void sort(int a[],int n)
{
    int i,j,k,t;
    for(i=0;i<n-1;i++){
    k=i;
    for(j=i+1;j<n;j++){
        if(a[j]>a[k])
        {
            k=j;
            t=a[k];a[k]=a[i];a[i]=t;
        }
    }    
    }
}
void main()
{
    int a[10]={0};
    for (int i = 0; i < 10; i++) 
    {
        scanf("%d", &a[i]);
    }
    sort(a,10);
    for(int j=0;j<10;j++){
    printf("%d\t",a[j]);}
    system("pause");
}