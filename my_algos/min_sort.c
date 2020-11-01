#include <stdio.h>

#include "algo_interface.h"

static void swap_int_ptr(int* a, int *b);
int* index_of_min(int *arr, const size_t size);

void algo_sort_func(rand_array_t ra){
    puts("Starting sort");
    size_t size = ra.size;
    int * arr = ra.arr;

    if(arr == NULL){
        fprintf(stderr, "Error : the given array is <NULL>. Aborting\n");
    }

    while(size > 1){
        int* min_index = index_of_min(arr, size);
        swap_int_ptr(min_index, arr);

        --size;
        ++arr;
    }
    puts("Sorting finished :)");
}

static void swap_int_ptr(int* a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int* index_of_min(int *arr, const size_t size){
    size_t min_index = 0;
    int min = arr[0];
    for(size_t i = 0; i < size; i++){
        if(arr[i] < min){
            min = arr[i];
            min_index = i;
        }
    }

    return ((int *)(arr + min_index));
}