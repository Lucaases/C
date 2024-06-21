#include <stdio.h>

int main() {
    int sum = 0, i = 1, flag = 1;
    while (i <= 101) {
        sum += flag * i;
        i += 2;
        flag = -flag;
    }
    printf("The result is %d\n", sum);
    system("pause");
    return 0;
}
