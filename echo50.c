#include "stdio.h"
#include "string.h"
void sort(void *p[10])
{
    int i,j;
    char *t;
    for(i=0;i<9;i++){
        for(j=0;j<9-i;j++){
            if(strcmp(p[j],p[j+1])>0){
                t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
            }
        }
    }
}

int main()
{
    const char *str[] = {"red","blue","perple","green","yellow","orange","black","pink","white","brown"};
    int i;
    sort(str);
    for(i=0;i<10;i++){
        printf("%s\n",str[i]);}
    system("pause");
    return 0;
}