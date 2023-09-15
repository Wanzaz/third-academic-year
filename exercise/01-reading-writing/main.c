/*
 * Projekt: DeBAGR
 * Autor:
 * Datum: now
 *           ^ Dej sem textový kurzor a udělej Ctrl+J
 */

#include <stdio.h>
#include <stdlib.h>

/**
  Pole má být naplněno posloupností čísel 1, 2, 3, 4, ... 10
  Pomocí debugeru odlaď s co nejmenším počtem zásahů do kódu, aby tomu opravdu
  tak bylo.
**/


int funkce()
{
    int k=5, i=3;
    return (10-k+i*2); // -1
}

void vypisPole(int pole[], int delka)
{
  for (int i = 0; i < delka; ++i) // (int i = 0; ++i; i > delka)
  {
    printf("pole[%d]: %2d\n", i, pole[i]);
  }
}

typedef struct _pom Tpom;

struct _pom
{
  int a;
  int b;
};


int main()
{
    int * pole = malloc(10*sizeof(int));
    int i, j, k, m=7;

    // int *u;
    int *v = &m;

    Tpom pom = { .a = m, .b = 3 };
    Tpom *pp = &pom;

    i=j=k=2;

    // v komentářích je předpokládaný index

    pole[m-i]=4+k;  // 5 - 2+k;

    pole[pole[m-i] - 2]= pole[*v-i] - 1; // 4 - pole[pole[m-i]]= pole[*v-i] +1;

    pole[i-1] = k;  //1 - pole[i=i-1] = k;

    pole[i] = pp->a - 4;   //2 - pole[pole[i]] = m=pp->a - 5;

    pole[m - 7] = i - 1;  //0 - pole[m] = i;

    pole[j+1] = 3*k-2;   //3

    pole[3+pole[j+i]+1] = funkce() - 1; //9

    pole[k=3*k] = 8 - 1;   //6

    pole[m*4 - 20] = pole[k] +2;   //8

    pole[7] = k + 3*i - 2* (int)*v + 10; //7

    vypisPole(pole, 10);

    free(pole);

    return 0;
}
