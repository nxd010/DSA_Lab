#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int main() {
    int matrix[MAX_ROWS][MAX_COLS];
    int i, j, rows, cols, count = 0;

   
    printf("Enter rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

   
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 0)
                count++; 
        }
    }

    if (count > (rows * cols) / 2) {
        printf("a sparse matrix.\n");
    } else {
        printf("not a sparse matrix.\n");
    }

    return 0;
}
