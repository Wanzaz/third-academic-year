#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

enum eChyby { EOK, ENECEKANAZAVIRACI, ENEZAVRENA, EPAMET, ENEZNAMA };

const char * CHYBY[] = {
    [EOK] = "Vsechno je v poradku.",
    [ENECEKANAZAVIRACI] = "Narazil jsem na necekanou zaviraci zavorku",
    [ENEZAVRENA] = "Narazil jsem na neuzavrenou zavorku",
    [EPAMET] = "Chyba alokace pameti",
    [ENEZNAMA] = "Necekana chyba! Utikej pryc!!",
};

void hlaseni(int kod)
{
    if (kod < EOK || kod > ENEZNAMA) {
        kod = ENEZNAMA;
    }

    printf("%s\n", CHYBY[kod]);
}

bool jeToOteviraciZavorka(char znak)
{
    return znak == '(' ||
           znak == '[' ||
           znak == '{' ||
           znak == '<';
}

bool jeToZaviraciZavorka(char znak)
{
    return znak == ')' ||
           znak == ']' ||
           znak == '}' ||
           znak == '>';
}

int oteviraci2zaviraci(int znak)
{
    if (znak == '(') return ')';
    if (znak == '[') return ']';
    if (znak == '{') return '}';
    if (znak == '<') return '>';

    return znak;
}


int testujZavorky(FILE *f, Tzasobnik *z)
{
    char znak;
    while (fscanf(f, "%c", &znak) == 1) {
        if (jeToOteviraciZavorka(znak)) {
            if(!zasPush(z, znak)) {
                return EPAMET;
            }
        } else if (jeToZaviraciZavorka(znak)) {
            char oteviraci = z->vrchol->hodnota;
            char ocekavanyZaviraci = oteviraci2zaviraci(oteviraci);

            if (zasIsEmpty(z) || znak != ocekavanyZaviraci) {
                return ENEZAVRENA; // Unmatched closing bracket
            } else {
                zasPop(z, &znak);
            }
        }
    }

    if (!zasIsEmpty(z)) {
        return ENECEKANAZAVIRACI; // Unmatched opening bracket
    }

    return EOK;
}

int zavorky(FILE *in)
{
    Tzasobnik *z = zasInit();


    int vysledek = testujZavorky(in, z);

    free(z);

    return vysledek;
}


int main()
{
    FILE *in = stdin;
    /* FILE *in = fopen("cviceni-pr5-03-data1.html", "r"); */
    /* FILE *in = fopen("cviceni-pr5-03-data2.html", "r"); */

    int vysledek = zavorky(in);

    hlaseni(vysledek);

    return 0;
}
