#include "stdio.h"
int main()
{
    char a[1000];
    gets(a);
    int i;
    int length=0;
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]!='\0'&&a[i]!=' '){
        length++;}
    }    
printf("length = %d",length);
system("pause");
return 0;
}
  