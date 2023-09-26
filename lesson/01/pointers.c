#include <stdio.h>

// pro link list
typedef struct _prvek Tprvek;
struct _prvek {
    int hodnota;
    Tprvek * dalsi;
};


/* typedef struct { */
/*     int pp; */
/*     Tprvek */
/* } Tosoba; */

typedef struct _osoba Tosoba;
struct _osoba {
    int pp;
};


// rika se tomu procedura kvuli voidu
void ufikniPrst(Tosoba *x)
{
    // diky * x se ta zmena propise
    x->pp -= 1;
}

void pricti1(float *x)
{
    // kdyz je to obycejna promena tak tam * musi byt
    *x += 1.0;
}

int main(int argc, char *argv[])
{
    Tosoba a;
    Tosoba * x;
    x = &a;
    ufikniPrst(&a); // musim predat takze pisu amprsant
    ufikniPrst(x); // uz nemusim protoze to je ukazatel
    
    return 0;
}
