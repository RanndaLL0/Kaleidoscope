#ifndef UTILS_H
#define UTILS_H

        struct vector {
                void **arr;
                int capacity;
                int size;

                void (* push)(struct vector *self_vector, void *item);
                void (* vector_destructor)(struct vector *self_vector);
        }; 


        struct vector vector_constructor();

#endif // !UTILS_H
