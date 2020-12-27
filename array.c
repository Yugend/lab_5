#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* create_array(int length){
    int* arr = (int*)malloc(length * sizeof(int));
    return arr;
}

int* init_array(int* arr, int length){
    srand(time(0));
    int i = 0;
    for(i = 0; i < length; i++){
        arr[i] = rand()%100 - 50;
    }
    return arr;
}

void print_array(int* arr, int length){
    int i = 0;
    for(i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int sum_max_arr(int* arr, int length){
    int max1 = -100, max2 = -100;
    int i = 0;
    for(i = 0; i < length; i++){
        if(arr[i] < 0){
            if(arr[i] > max1){
                max2 = max1;
                max1 = arr[i];
            }
            else if(arr[i] > max2){
                max2 = arr[i];
            }
        }
    }
    if(max1 == -100)
        return 0;
    else if (max2 == -100)
        return max1;
    else
        return max1 + max2;
}
