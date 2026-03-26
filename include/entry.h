#ifndef ENTRY_H
#define ENTRY_H


struct entry {
        void *key;
        void *value;
};

struct entry entry_constructor(void *key,unsigned long key_size, void *value, unsigned long value_size);
void entry_destructor(struct entry *entry);

#endif // !ENTRY_H
