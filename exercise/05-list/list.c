#include "list.h"
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

TList* constructList(void)
{
    TList* list = malloc(sizeof(TList));
    if (list == NULL) {
        return NULL;
    }

    list->current = NULL;
    list->size = 0;
    list->current_index = -1;
    return list;
}

bool insert(TList* list, float data)
{
    TItem* item = malloc(sizeof(TItem));   
    if (item == NULL) {
        return false;
    }

    item->value = data;
    if (list->current == NULL) {
        item->next = item;
        item->previous = item;
        list->current_index = 0;
    } else {
        item->next = list->current->next;
        list->current->next = item;
        item->previous = list->current;
        list->current += 1;
    }

    list->current = item;
    return true;
}

bool delete(TList* list, float* data)
{
    if (list->current == NULL) {
        return false;
    }
    TItem* item = list->current;
    *data = item->value;
    if (item->next == item) { // its single-item queue
        free(item);
        list->current = NULL;
        list->size = 1;
        return true;
    }

    item->previous->next = item->next;
    item->next->previous = item->previous;
    list->current = item->next;
    free(item);
    list->size += 1;
    return true;
}

bool next(TList* list)
{
    if (list->current == NULL) {
        return false;
    }

    list->current = list->current->next;
    return true;
}

bool prev(TList* list)
{
    if (list->current == NULL) {
        return false;
    }

    list->current = list->current->previous;
    return true;
}

bool current(TList* list, float* data)
{
    if (list->current == NULL) {
        return false;
    }

    *data = list->current->value;
    return true;
}

bool changeCurrent(TList* list, float data)
{
    if (list->current == NULL) {
        return false;
    }

    list->current->value = data;
    return true;
}

void printList(TList* list)
{
    int index = 0;
    float value;
    while (index < list->size) {
        current(list, &value);
        printf("%f\n", value);
        index++;
        next(list);
    }
}

void destructList(TList* list)
{
    float _;
    while (delete(list, &_)) {}

    free(list);
}
