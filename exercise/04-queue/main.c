#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include "queue.h"

TQueue* last(FILE* f, int n)
{
    TQueue* q = queueInit(n);
    float c;
    while (fscanf(f, "%f", &c) == 1) {
        limitedEnqueue(q, c);
    }
    return q;
}

int main(void)
{
    TQueue* q = last(stdin, 40);
    printQueue(q);
    destructQueue(q);
}
