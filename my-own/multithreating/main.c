#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void* myTurn(void * arg)
{
    int *iptr = (int *)malloc(sizeof(int));
    for (int i = 0; i < 8; i++) {
        sleep(1);
        printf("My Turn! %d %d\n", i, *iptr);
        (*iptr)++;
    }

    return iptr;
}

void yourTurn()
{
    for (int i = 0; i < 3; i++) {
        sleep(1);
        printf("Your Turn! %d\n", i);
    }
}

int main(int argc, char *argv[])
{
    pthread_t newThread;
    int *result;

    pthread_create(&newThread, NULL, myTurn, NULL);
    /* myTurn(); */
    yourTurn(); // It won't be executed because it is only one process
                // so there has to be the pthreads used to create another process

    // wait until the thread is done before we exit
    pthread_join(newThread, (void *)&result);
    printf("thread's done: *result=%d\n", *result);


    return 0;
}
