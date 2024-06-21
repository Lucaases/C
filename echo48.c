#include "stdio.h"
void compare(int a,int b)
{
    if(a>b){
    printf("较大数为%d,较小数为%d\n",a,b);}
    else if (a<b){
    printf("较大数为%d,较小数为%d\n",b,a);}
    else{
    printf("两数相等\n");}
}
int main()
{
    void (*p)(int,int);
    p=compare;
    int a,b;
    scanf("%d %d",&a,&b);
    (*p)(a,b);
    system("pause"); 
    return 0;
}