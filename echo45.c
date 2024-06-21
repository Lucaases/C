#include "stdio.h"
#include "string.h"
void reverse(char *p,int n)
{
    char t;
    for(char *front=p,*back=p+(n-1);front<back;front++,back--){
       t=*front;
       *front=*back;
       *back=t;
    }
}
char main()
{
    int n;
    char a[100]="/0";
    printf("Please enter a Character string\n");
    fgets(a,sizeof(a),stdin);
    n=strlen(a);
    reverse(a,n);
    printf("the Character string after reversing:%s\n",a);
    system("pause");  
    return 0;
}