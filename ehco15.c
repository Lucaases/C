#include <stdio.h>

int main() {
   int sum=0;
   for(int i=1;i<=1000;sum=sum+i,i+=2);
    printf("The result is %d\n",sum);
    system("pause");
    return 0;
}