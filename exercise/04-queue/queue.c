#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"


TQueue * queueInit(int max)
{
    TQueue *q = malloc(sizeof(TQueue));
    if (q == NULL) {
        return NULL;
    }

    q->first = NULL;
    q->last = NULL;
    q->length = 0;
    q->max = max;

    return q;
}

bool enqueue(TQueue *q, float data)
{
    TElement *new = malloc(sizeof(TElement));
    if (new == NULL) {
        return false;
    }
    new->value = data;
    new->next = NULL;

    q->last->next = new;
    q->last = new;

    if (q->first == NULL) {
        q->first = new;
    }
    q->length++;

    return true;
}

bool dequeue(TQueue *q, float *d)
{
    if (q->first == NULL) {
        return false;
    }

    TElement *toRemove = q->first;
    *d = toRemove->value;
    q->first = toRemove->next;

    free(toRemove);

    if (q->first == NULL) {
        q->last = NULL;
    }
    q->length--;

    return true;
}

bool limitedEnqueue(TQueue* q, float value)
{
    if (q->length == q->max) {
        float _;
        dequeue(q, &_);
    }

    return enqueue(q, value);
}

void printQueue(TQueue* q)
{
    float element;
    for (int i = 0; i < q->length; i++) {
        dequeue(q, &element);
        printf("%f\n", element);
    }
}

void destructQueue(TQueue* q)
{
    float _;
    while (dequeue(q, &_));
    free(q);
}



