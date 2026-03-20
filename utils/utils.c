#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include "utils.h"

void push(struct vector *self_array, void *item, unsigned int item_size) {
        
        if (self_array->size >= self_array->capacity) {

                int new_capacity = (self_array->capacity == 0) ? 4 : self_array->capacity * 2;
                void *new_arr = realloc(self_array->arr, new_capacity * item_size);
                
                if (new_arr == NULL) {
                        perror("Erro ao realocar memoria para o vetor");
                        exit(EXIT_FAILURE);
                }

                self_array->arr = new_arr;
                self_array->capacity = new_capacity;
        }

        char *destination = (char *)self_array->arr + (self_array->size * item_size);
        memcpy(destination, item, item_size);

        self_array->size++;
}

struct vector vector_constructor() {
        
        struct vector *vec = (struct vector *)malloc(sizeof(struct vector));

        if (vec == NULL) {
                perror("Erro ao criar novo vetor");
                exit(EXIT_FAILURE);
        }

        vec->arr = NULL;
        vec->capacity = 0;
        vec->size = 0;
        vec->push = push;

        return *vec;
}


void vector_desctructor(struct vector *vec) {
        
        for(int i = 0; i < vec->size; i++) {
                free(vec->arr[i]);
        }
        free(vec);
}
