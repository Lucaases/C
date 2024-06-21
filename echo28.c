#include "stdio.h"  
#include <string.h>  
int main()  
{
    char a[100] = {"\0"};  
    gets(a);  
    char b[100] = {"\0"};  
    gets(b);  
    int i;  
    int len1 = strlen(a);    
    int len2 = strlen(b);  
    int result = 0;  
    if (len1 == len2) {  
        for (i = 0; i < len1; i++) {  
            if (a[i] == b[i]) {  
                result = 0;  
                break;  
            }  
        }  
    } else if (len1 > len2) {  
        result = 1;  
    } else if (len1 < len2) {  
        result = -1;  
    }  
    printf("result = %d\n", result);  
    system("pause");  
    return 0;  
}
