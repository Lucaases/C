#include <stdio.h>
#include <math.h>

int main() {
    double r,a;
    int n;
    int p=1;

    printf("�������������ʣ�%%����");
    scanf("%lf", &r);

    printf("�������������꣩��");
    scanf("%d", &n);

    r = r / 100; 

    a = p * pow(1 + r, n); 

    printf("��������ȵı���Ϊ��%g\n", a);

    system("pause");

    return 0;
}
