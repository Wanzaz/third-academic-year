#ifndef STACK_H_IMPORTED
#define STACK_H_IMPORTED

#include<stdbool.h>

typedef struct _TItem {
    float value;
    struct _TItem* next;
    struct _TItem* previous;
} TItem;

typedef struct {
    TItem* current;
    int current_index;
    int size;
} TList;

TList* constructList(void);

bool insert(TList* list, float data);

bool delete(TList* list, float* data);

bool next(TList* list);

bool prev(TList* list);

bool current(TList* list, float* data);

bool changeCurrent(TList* list, float data);

void printList(TList* list);

void destructList(TList* list);

#endif
