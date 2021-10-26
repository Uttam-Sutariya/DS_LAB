//Read two matrices first 3x2 and second 2x3, perform multiplication operation and store result in third matrix and print it

#include <stdio.h>
#include <stdlib.h>

//defining rows & columns
#define R1 3
#define C1 2
#define R2 2
#define C2 3

void mulMat(int mat1[][C1], int mat2[][C2]) {
	int rslt[R1][C2];

	printf("\nMultiplication of given two matrices is:\n\n");

	for (int i = 0; i < R1; i++) {
		for (int j = 0; j < C2; j++) {
			rslt[i][j] = 0;

			for (int k = 0; k < R2; k++) {
				rslt[i][j] += mat1[i][k] * mat2[k][j];
			}

			printf("%d\t", rslt[i][j]);
		}

		printf("\n\n");
	}
}

int main(void) {
    int mat1[R1][C1];
    int mat2[R2][C2];

    if (C1 != R2) {
        printf("\nCan't multiply matrices\n\n");
		exit(EXIT_FAILURE);
	}

    //reading matrix
    printf("\nEnter elements of 1st matrix\n");
    for(int i = 0 ; i<R1 ; i++){
        for(int j = 0 ; j<C1 ; j++){
            scanf("%d", &mat1[i][j]);
        }
    }
    
    printf("\nEnter elements of 2nd matrix\n");
    for(int i = 0 ; i<R2 ; i++){
        for(int j = 0 ; j<C2 ; j++){
            scanf("%d", &mat2[i][j]);
        }
    }

	mulMat(mat1, mat2);

	return 0;
}

