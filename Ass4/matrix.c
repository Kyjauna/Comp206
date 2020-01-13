//Kyjauna Marshall
//260802473

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void fillMatrix(int matrix[ROWS][COLS]){
srand((unsigned)clock()); // so its different at every runtime 
int i, j;

for(i = 0; i < ROWS; ++i)

    for (j = 0; j < COLS; ++j)  // iterates through the cols then moves to the next row

        matrix[i][j] = rand() %100+1; //sets a random value at location [i][j] in the matrix
}

void printMatrix(int matrix[ROWS][COLS]){
int i,j;
for(i = 0; i < ROWS; i++){
        for (j = 0; j < COLS; j++){ //iterates through five cols then moves to next row
                printf("%d ", matrix[i][j]); // prints every element at [i][j] in the matrix
        }
     printf("\n");
}
printf("\n");
}

void transposeMatrix(int matrix[ROWS][COLS]){
int m,l;
        for (m = 0; m < ROWS; m++){
                for (l = 0; l < m; l++){ //iterates over only half of the matrix
                        int temp = *(*(matrix+m)+l); // uses tmp to hold value to be transposed
                        *(*(matrix+m)+l) = *(*(matrix+l)+m); //switches the pointer location
                        *(*(matrix+l)+m) = temp; // finally assigns the transposed value
                }
        }
}

void multiplyMatrix(int m1[2][COLS], int m2[ROWS][COLS],int resultMatrix[ROWS][COLS]){
int r, c, h;
int i, j;

        // Initializing elements of matrix mult to 0.
        for(i = 0; i < ROWS; ++i)
        {
		for(j = 0; j < COLS; ++j)
                {
                        resultMatrix[i][j] = 0;
                }

        }
	//basic matrix multiplication 
        for (r = 0; r < 2; r++){
                for(c = 0; c < COLS; c++){
                        for(h = 0; h < COLS; h++){
                                resultMatrix[r][c] =resultMatrix[r][c]+ m1[r][h]*m2[h][c];
                        }
                }

        }
}
int main()
 {
        int matrix[ROWS][COLS];
        fillMatrix(matrix);
        printMatrix(matrix);

        transposeMatrix(matrix);
        printMatrix(matrix);

        int matrix2[2][COLS]={0,1,2,3,4,5,6,7,8,9};
        int matrixResult[ROWS][COLS];

        multiplyMatrix(matrix2, matrix, matrixResult);
        printMatrix(matrixResult);

        return 0;
 }

