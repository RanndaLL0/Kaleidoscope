#ifndef linked_list_h
#define linked_list_h

        #include "node.h"
        
        /*
         *The "compare" function will be used to perform 
         *comparisons between the data in the structure.
         * */

        struct linked_list {

                int length;
                struct Node *head;

                void (*insert)(struct linked_list *list, int index, void *data, unsigned long data_size);

                void (*remove)(struct linked_list *list, int index);

                short (*search)(struct linked_list *list, void *query, int (*compare)(void *a, void *b));

                void *(*retrieve)(struct linked_list *list, int index);

                void (*sort)(struct linked_list *list, int (*compare)(void *a, void *b));
        };

        struct linked_list linked_list_constructor(void);
        void linked_list_destructor(struct linked_list *list);

#endif // !
