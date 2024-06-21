#include <stdio.h>

int main() {
    double data1, data2, result;
    char op;
    printf("Enter two operands and operator: ");
    scanf("%lf %lf %c", &data1, &data2, &op);
    switch (op) {
        case '+':
            result = data1 + data2;
            break;
        case '-':
            result = data1 - data2;
            break;
        case '*':
            result = data1 * data2;
            break;
        case '/':
            result = data1 / data2;
            break;
        default:
            printf("Invalid operator");
            return 1;
    }
    printf("%.2f %c %.2f = %.2f\n", data1, op, data2, result);
    system("pause");
    return 0;
}