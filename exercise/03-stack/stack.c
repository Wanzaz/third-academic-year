#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"


Tzasobnik * zasInit(void)
{
    Tzasobnik *z = malloc(sizeof(Tzasobnik));
    if (z == NULL) {
        return NULL; // Nepodarilo se alokovat pamet
    }
    z->vrchol = NULL;
    z->vyska = 0;

    return z;
}

void zasFree(Tzasobnik *z)
{
    while (!zasIsEmpty(z)) {
        char data;
        zasPop(z, &data);
    }

    free(z);
}

bool zasPush(Tzasobnik *z, char data)
{
    Tprvek *novy = malloc(sizeof(Tprvek));
    if (novy == NULL) {
        return false; // Nepodarilo se alokovat pamet
    }
    novy->hodnota = data;
    novy->dalsi = z->vrchol;
    z->vrchol = novy;
    z->vyska++;

    return true; // Uspesne vlozeni
}


bool zasPop(Tzasobnik *z, char *d)
{
    if (zasIsEmpty(z)) {
        return false; // Zasobnik je prazdny
    }
    Tprvek *odebrany = z->vrchol;
    *d = odebrany->hodnota;
    z->vrchol = odebrany->dalsi;
    free(odebrany);
    z->vyska--;

    return true; // Uspesne odstranen
}

bool zasIsEmpty(Tzasobnik *z)
{
    return z->vrchol == NULL;
}

bool zasTop(Tzasobnik *z, char *d)
{
    if (zasIsEmpty(z)) {
        return false;
    }
    *d = z->vrchol->hodnota;

    return true;
}




