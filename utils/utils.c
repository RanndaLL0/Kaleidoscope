#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "utils.h"

void push(struct vector *self_array, void *item) {
        
        if (self_array->size >= self_array->capacity) {

                int new_capacity = (self_array->capacity == 0) ? 4 : self_array->capacity * 2;
                void **new_arr = realloc(self_array->arr, new_capacity * sizeof(void *));
                
                if (new_arr == NULL) {
                        perror("Erro ao realocar memoria para o vetor");
                        exit(EXIT_FAILURE);
                }

                self_array->arr = new_arr;
                self_array->capacity = new_capacity;
        }
        
        self_array->arr[self_array->size++] = item;
}


void vector_destructor(struct vector *self_vector) {

        if (self_vector->arr != NULL) {       
                free(self_vector->arr); 
                self_vector->arr = NULL;
        }

        self_vector->size = 0;
        self_vector->capacity = 0;
}

struct vector vector_constructor() {
        
        struct vector vec;

        vec.arr = NULL;
        vec.capacity = 0;
        vec.size = 0;
        vec.push = push;
        vec.vector_destructor = vector_destructor;

        return vec;
}
