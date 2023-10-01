#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* myTurn(void * arg)
{
    while (1) {
        sleep(1);
        printf("My Turn!\n");
    }

    return NULL;
}

void* myTurn2(void * arg)
{
    for (int i = 0; i < 8; i++) {
        sleep(1);
        printf("My Turn! %d\n", i);
    }

    return NULL;
}

void yourTurn()
{
    while (1) {
        sleep(1);
        printf("Your Turn!\n");
    }
}

void yourTurn2()
{
    for (int i = 0; i < 3; i++) {
        sleep(1);
        printf("Your Turn! %d\n", i);
    }
}

int main(int argc, char *argv[])
{
    pthread_t newThread;

    pthread_create(&newThread, NULL, myTurn2, NULL);
    /* myTurn(); */
    yourTurn2(); // It won't be executed because it is only one process
                // so there has to be the pthreads used to create another process

    // wait until the thread is done
    pthread_join(newThread, NULL);

    return 0;
}
