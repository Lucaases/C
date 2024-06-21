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
    printf("������һ��4x4�ľ���\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("ת�ú�ľ���Ϊ��\n");
    transpose(a,&max, &min);
    printf("���ֵΪ��%d\n", max);
    printf("��СֵΪ��%d\n", min);
    system("pause");
    return 0;
}