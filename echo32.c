#include <stdio.h>
int GCD(int a,int b)
{
    if(a%b==0)
    {return b;}
    else
    {return GCD(b,a%b);}
}
int main()
{
    int x,y;
    scanf("%d %d",&x,&y);
    printf("%d\n",GCD(x,y));
    system("pause");
    return 0;
}