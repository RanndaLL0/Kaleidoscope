#ifndef UTILS_H
#define UTILS_H

        struct vector {
                void **arr;
                int capacity;
                int size;

                void (*push)(struct vector *self_vector, void *item, unsigned int item_size);
        }; 


        struct vector vector_constructor();

#endif // !UTILS_H
