#include "stdio.h"
int max(int a,int b,int c){
int m;
if(a>b&&a>c){
m = a;}
else if(b>a&&b>c){
m = b;}
else if(c>a&&c>b){
m = c;}
return m;
}
int min(int a,int b,int c){
int m;
if(a>b&&b>c){
m = c;}
else if(b>a&&c>a){
m = a;}
else if(c>a&&a>b){
m = b;}
return m;
}
int main()
{
    int d,e,f;
    scanf("%d,%d,%d",&d,&e,&f);
    printf("max=%d,min=%d",max(d,e,f),min(d,e,f));
    system("pause"); 
    return 0;
}
