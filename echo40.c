#include <stdio.h>
void transpose(int a[][4], int *max, int *min) 
{
    int i, j;
    *max = a[0][0];
    *min = a[0][0];
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (a[i][j] > *max) {
                *max = a[i][j];
            }
            if (a[i][j] < *min) {
                *min = a[i][j];
            }
            printf("%d", a[j][i]);
        }
        printf("\n");
    }
}

int main() {
    int a[4][4], i, j;
    int max, min;
    printf("请输入一个4x4的矩阵：\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("转置后的矩阵为：\n");
    transpose(a,&max, &min);
    printf("最大值为：%d\n", max);
    printf("最小值为：%d\n", min);
    system("pause");
    return 0;
}