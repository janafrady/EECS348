/*
Name: Jana Frady
KUID: 3085051
Lab Session: Thursday 4 p.m.
Lab Assignment Number: 05
Program Description: This program manipulates two matrices.
Collaborators: None
*/

#include <stdio.h>
#define SIZE 5

// adds two matrices together
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]){
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            printf("%d ",m1[i][j] + m2[i][j]);
        }
        printf("\n");
    }
}

// multiplies two matrices together
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]){
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            int sum = 0;
            for (int k=0; k<SIZE; k++){
                sum += m1[i][k] * m2[k][j];
            }
            printf("%d ",sum);
        }
        printf("\n");
    }
}

// transposes matrix
void transposeMatrix(int tom[SIZE][SIZE]){
    int transpose[SIZE][SIZE];
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            transpose[i][j] = tom[j][i];
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
}

// prints matrix in user-friendly format
void print_matrix(int tim[SIZE][SIZE]){
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            printf("%d ", tim[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int m1[SIZE][SIZE] = { //given matrix
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };

    int m2[SIZE][SIZE] = { //given matrix
        {25,24,23,22,21},
        {20,19,18,17,16},
        {15,14,13,12,11},
        {10,9,8,7,6},
        {5,4,3,2,1}
    };

    printf("Matrix A\n"); //prints matrices
    print_matrix(m1);
    printf("\nMatrix B\n");
    print_matrix(m2);
    printf("\nA transpose =\n"); //transposes matrices
    transposeMatrix(m1);
    printf("\nB transpose =\n");
    transposeMatrix(m2);
    printf("\nA+B = B+A = \n"); // adds matrices
    addMatrices(m1,m2);
    printf("\nA*B =\n"); // multiplies matrices
    multiplyMatrices(m1,m2);
    printf("\nB*A =\n");
    multiplyMatrices(m2,m1);

}