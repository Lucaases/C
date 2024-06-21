#include  "stdio.h"
int pri(int a){
    int i;
    if(a==0||a==1)
    {printf("it is not a prime number\n");}
    else{
        for(i=2;i<a;i++){
            if(a%i==0)
            {
                printf("it is not a prime number");
                break;}
            else{
                printf("it is a prime number\n");
                break;
                }
            }
            }
    return 0;
}            
int main()
{
    int b;
    scanf("%d",&b);
    pri(b);
    system("pause");
    return 0;
}