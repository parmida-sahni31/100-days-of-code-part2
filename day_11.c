#include <stdio.h>

int main() {
    int r, c;

    scanf("%d %d", &r, &c);

    int A[r][c], B[r][c], C[r][c];

    // Input Matrix A
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Input Matrix B
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Add matrices
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // Print Result Matrix
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
