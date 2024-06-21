#include <stdio.h>

int main() {
    printf("short int: %zu bytes\n", sizeof(short int));
    printf("int: %zu bytes\n", sizeof(int));
    printf("long int: %zu bytes\n", sizeof(long int));
    printf("unsigned int: %zu bytes\n", sizeof(unsigned int));
    printf("float: %zu bytes\n", sizeof(float));
    printf("double: %zu bytes\n", sizeof(double));
    printf("char: %zu bytes\n", sizeof(char));
    system("pause");
    return 0;
}