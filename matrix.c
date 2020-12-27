#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* create_matrix(int length1, int length2){
    int* matr = (int*)malloc(length1 * length2 * sizeof(int));
    return matr;
}

int* init_matrix(int* matr, int length1, int length2){
    srand(time(0));
    int i = 0;
    for(i = 0; i < length1 * length2; i++){
        matr[i] = rand()%100 - 50;
    }
    return matr;
}

void print_matrix(int* matr, int length1, int length2){
    int i = 0;
    int j = 0;
    for(i = 0; i < length1; i++){
        for(j = 0; j < length2; j++){
            printf("%d ", matr[i*length2 + j]);
        }
        printf("\n");
    }
}

int sum_max_matr(int* matr, int length1, int length2){
    int max1 = -100, max2 = -100;
    int i = 0, j = 0;
    for(i = 0; i < length1; i++){
        for(j = 0; j < length2; j++){
            if(matr[i * length2 + j] < 0){
                if(matr[i * length2 + j] > max1){
                    max2 = max1;
                    max1 = matr[i * length2 + j];
                }
                else if(matr[i * length2 + j] > max2){
                    max2 = matr[i * length2 + j];
                }
            }
        }
    }
    if(max1 == -100)
        return 0;
    else if(max2 == -100)
        return max1;
    else
        return max1 + max2;
}
