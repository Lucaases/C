#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int max, min;
    max = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
    min = (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);

    printf("%d\n", max);
    printf("%d\n", min);
    system("pause");
    return 0;
}

