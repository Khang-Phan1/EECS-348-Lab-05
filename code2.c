/*
Name: Khang Phan
KUID:  3122346
Lab Session: Friday 4 p.m.
Lab Assignment: 05
Description: Takes in two matrices and performs multiple operations on them
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
//given constant size, it is assumed that all matrices will be square matrix of the same size for this program

void printMatrix(int m[SIZE][SIZE]) {
    //prints each column with a space in between, each row is separated by a new line
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int sum[SIZE][SIZE]) {
    //adds each corresponding matrix element from m1 and m2 and places sum into 2d array sum
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            sum[i][j] = m1[i][j]+m2[i][j];
        }
    }
}

void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int product[SIZE][SIZE]) {
    //multiplies each element in each row of m1 by each element in each col of m2, adds them together, places in 2d array product
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            product[i][j] = m1[i][0]*m2[0][j] + m1[i][1]*m2[1][j] + m1[i][2]*m2[2][j] + m1[i][3]*m2[3][j] + m1[i][4]*m2[4][j];
        }
    }
}

void transposeMatrix(int m[SIZE][SIZE], int transpose[SIZE][SIZE]) {
    //swaps the row/col for each element of m and places into transpose
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            transpose[i][j] = m[j][i];
        }
    }
}

int main() {
    //m1 and m2 are defined in the main function as shown in example input
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };
    int sum[SIZE][SIZE], product[SIZE][SIZE], transposeA[SIZE][SIZE], transposeB[SIZE][SIZE];
    addMatrices(m1, m2, sum);
    multiplyMatrices(m1, m2, product);
    transposeMatrix(m1, transposeA);
    transposeMatrix(m2, transposeB);

    printf("Matrix A:\n");
    printMatrix(m1);
    printf("Matrix B:\n");
    printMatrix(m2);

    //for each matrix operation, the 2d array variables are passed to the functions and return as the outputs
    printf("Addition of matrix A and matrix B:\n");
    printMatrix(sum);
    printf("Multiplication of matrix A and matrix B:\n");
    printMatrix(product);
    printf("Transpose of matrix A:\n");
    printMatrix(transposeA);
    printf("Transpose of matrix B:\n");
    printMatrix(transposeB);
}