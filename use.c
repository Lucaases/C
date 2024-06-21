#include "stdio.h"
int main()
{
while(1){
    int i;
    int a,b=5;
    scanf("%d",&a);
    if(a<=9){
        for(i=0;i<a;i++){
    printf("RA63624700%dSG\n",i+1);}}
    else if(10<a<100){
     for(i=0;i<a-10;i++){
    printf("RA6362470%dSG\n",i+10);}}
    else
    {printf("error\n");}
    system("pause");
}
}