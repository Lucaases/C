#include "stdio.h"
int main()
//{
    //int *p1;
    //double *p2;
    //char *p3;
    //float *p4;
   // printf("int: %zu bytes\n", sizeof(int));
   // printf("float: %zu bytes\n", sizeof(float));
   // printf("double: %zu bytes\n", sizeof(double));
    //printf("char: %zu bytes\n", sizeof(char));
    //printf("int: %zu bytes\n", sizeof(*p1));
   // printf("float: %zu bytes\n", sizeof(*p4));
   // printf("double: %zu bytes\n", sizeof(*p2));
    //printf("char: %zu bytes\n", sizeof(*p3));
    //system("pause");
//}

{
    int a = 3,b=6;
    int *p1,*p2,*p3;
    p1 = &a;
    p2 = &b;
	p3 = p1;
	*p3 = 8;
	printf("%x %x %x %x %x\n", a, &a, p3, *p3, &p3);
	printf("%d %d\n",a, b);
    system("pause");
    return 0;
}