#include <stdio.h>

int main()  
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};  
    int max = a[0];  
    int sum = 0;  
    printf("Enter 10 numbers: ");  
    for (int i = 0; i < 10; i++)  
        scanf("%d", &a[i]);

    for (int i = 0; i < 10; i++)  
    {  
        if (a[i] > max)  
            max = a[i];  
          
        sum += a[i];  
    }

    printf("Max: %d\n", max);  
    printf("Sum: %d\n", sum);  
    system("pause");  
    return 0;  
}