#include "stdio.h"
void reverse(int a[],int n)
{
    int k,b;
    for(int i=0;i<n/2;i++){
        k=a[i];
        a[i]=a[n-i-1];      
        a[n-i-1]=k;
        }
}
int main()
{
    int a[10]={0};
    for (int i = 0; i < 10; i++) 
    {
        scanf("%d", &a[i]);
    }
    reverse(a,10);
    for(int j=0;j<10;j++){
    printf("%d\t",a[j]);}
    system("pause");
}