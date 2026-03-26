#ifndef node_h
#define node_h

        /*
         * Nodes using a void pointer to represents any data type
         *
         * */

        struct Node {

                void *data;
                struct Node *next;
                struct Node *previous;
        };

        struct Node node_constructor(void *data, unsigned long dataSize);
        
        void node_destructor(struct Node* node);

#endif // !
