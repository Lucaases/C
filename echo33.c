#include <stdio.h>
int max(int a,int b)
{
    int m;
    return m=(a>b) ? a:b;
}
int min(int a,int b)
{
    int m;
    return m=(a<b) ? a:b;
}
int main()
{
    int x,y;
    scanf("%d %d",&x,&y);
    printf("max=%d,min=%d\n",max(x,y),min(x,y));
    system("pause");
    return 0;
}
