#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef struct _element TElement;

typedef struct _queue TQueue;

struct _element
{
    float value;
    TElement *next;

};

struct _queue 
{
    TElement * first;
    TElement * last;
    int length;
    int max;
};


/* \brief 
 *
 * \ param
 * \ param
 * \ return bool
 *
 */
TQueue * queueInit(int max);

bool enqueue(TQueue *q, float data);

bool dequeue(TQueue *q, float *d);

bool limitedEnqueue(TQueue* q, float value);

void printQueue(TQueue *q);

void destructQueue(TQueue *q);
#endif
