#include "stdio.h"
void move(char a,char b)
{
    printf("move a plate from %c to %c\n",a,b);
}
void hanoi(int n,char a,char b ,char c)
{
    if(n==0){
    printf("No plate to be moved\n");}
    else if(n==1){
    move(a,c);}
    else if(n>1){
    hanoi(n-1,a,c,b);
    move(a,c);
    hanoi(n-1,b,a,c);}
}
int main()
{
    int n=0;
    scanf("%d",&n);
    hanoi(n,'A','B','C');
    system("pause");
    return 0;
}
