#include <stdio.h>

int main() {    
    int rows, columns;    
    printf("Enter the number of rows and columns in the 2D array: ");    
    scanf("%d %d", &rows, &columns);

    int count[rows][columns];    
    for (int i = 0; i < rows; i++) {    
        for (int j = 0; j < columns; j++) {    
            count[i][j] = 0;    
        }    
    }

    printf("Enter the elements of the 2D array:\n");    
    for (int i = 0; i < rows; i++) {    
        for (int j = 0; j < columns; j++) {    
            scanf("%d", &count[i][j]);    
        }    
    }

    for (int i = 0; i < rows; i++) {    
        for (int j = 0; j < columns; j++) {    
            if (count[i][j] == 1) {    
                printf("%d ", count[i][j]);    
            }    
        }    
        printf("\n");    
    }
    system("pause");
    return 0;    
}




