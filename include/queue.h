#ifndef QUEUE_H 
#define QUEUE_H

        #include "linked_list.h"

        struct queue {

                struct linked_list linked_list;

                void (*pop)(struct queue *queue);
                void *(*peek)(struct queue *queue);
                void (*push)(struct queue *queue, void *data, unsigned long data_size);
        };

        struct queue queue_constructor(void);
        void queue_destructor(struct queue *queue);

#endif // !
