#ifndef DICT_H
#define DICT_H

        #include "entry.h"
        #include "../trees/tree.h"
        #include "../linked_list/linked_list.h"

        struct dictionary {

                struct binary_search_tree binary_search_tree;
                struct linked_list keys;

                void (* insert)(struct dictionary *dictionary, void *key, unsigned long key_size, void *value, unsigned long value_size);
                void * (* search)(struct dictionary *dictionary, void *key, unsigned long key_size);
        };

        struct dictionary dictionary_constructor(int (*compare)(void *entry_one, void *entry_two));
        void dictionary_destructor(struct dictionary *dictionary);

        int compare_string_keys(void *entry_one, void *entry_two);

#endif // !DICT_H

