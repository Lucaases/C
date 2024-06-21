#include "stdio.h"
void array(int *p, int n) {  
    double average1 = 0;
    int max = *p;
    int min = *p;
    double average;
    for (int i = 0; i < n; i++) {  
        average1+= *(p + i);  
        if (*(p + i) > max) {  
            max = *(p + i);  
        }  
        if (*(p + i) < min) {  
            min = *(p + i);  
        }  
    }  
    average = average1 / n;
    printf("average = %lf, max = %d, min = %d\n", average, max, min);  
}
int main() {  
    int a[100]={0};
    int n;
    printf("Please enter the value of the size of the array: ");  
    scanf("%d", &n);  
    for (int i=0;i<n;i++) {  
        scanf("%d",&a[i]);  
    }  
    array(a, n);  
    system("pause");  
    return 0;  
}
