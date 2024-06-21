#include "stdio.h"
int main()
{
    char a[1000];
    int letter=0,number=0,space=0,other=0;
    int i;
    gets(a);
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]>='a'&&a[i]<='z'||a[i]>='A'&&a[i]<='Z')
        {letter++;}
        if(a[i]>='1'&&a[i]<='9')
        {number++;}
        if(a[i]==' ')
        {space++;}
        else
        {other++;}
    }
    printf("letter=%d,number=%d,space=%d,other=%d\n",letter,number,space,other);
    system("pause");
    return 0;
}
        