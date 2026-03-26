#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../utils/utils.h"

int main()
{
        int number = 2;
        struct vector dinamic_array = vector_constructor();
        dinamic_array.push(&dinamic_array, &number);

        for (int i = 0; i < dinamic_array.size; i++) {
                printf("numero: %d \n", *(int *)((char *)dinamic_array.arr + i * sizeof(int)));
        }

        dinamic_array.vector_destructor(&dinamic_array);

        printf("Compilou com sucesso");
        return EXIT_SUCCESS;
}
