/*
 * Projekt: pr5-cviko01-
 * Autor: Donald Kačer -- podepiš se sem (a taky přejmenuj název adresáře)
 * Datum: doplň
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // pro práci s typem bool a konstantami true a false
#include <ctype.h>   // isalpha, isspace, islower, isupper, ...


typedef struct pole
{
    float *prvek;
    int delka;
} Tpole;


Tpole * novePole(int delka)
{
    Tpole * sp = malloc(sizeof(Tpole));

    if (sp == NULL) {
        return NULL;
    }

    sp->prvek = malloc(delka*sizeof(float));

    if (sp->prvek == NULL) {
        free(sp); // nezapomeň uvolnit už vyrobenou strukturu
        return NULL;
    }

    sp->delka = delka;
    return sp;
}

void uvolniPole(Tpole *p)
{
    free(p->prvek);

    free(p);
}

int countNumbersInFile(FILE *f)
{
    int count = 0;
    float value;

    while (fscanf(f, "%f", &value) == 1) {
        count++;
    }

    return count;
}

Tpole *nactiSoubor(FILE *f)
{
    int pocet = countNumbersInFile(f);
    Tpole *p = novePole(pocet);
    if (p == NULL) {
        return NULL;
    }

    rewind(f);

    for (int i = 0; i < pocet; i++) {
        if (fscanf(f, "%f", &(p->prvek[i])) != 1) {
            // Failed to read an element, adjust the length and return
            p->delka = i;
            return p;
        }
    }

    return p;
}

void vytiskniOpacne(FILE *out, Tpole * p)
{
  fprintf(out, "Delka souboru: %d\n", p->delka);

  for (int index = 0; index < p->delka; index++) {
      fprintf(out, "%.2f\n", p->prvek[p->delka - index - 1]);
  }
}

int main(void)
{
    char vstupniCesta[100];
    printf("Zadej cestu k vstupnimu souboru: ");
    scanf("%99s", vstupniCesta);


    FILE * f = fopen(vstupniCesta, "r");
    if (f == NULL) {
        perror("Nepovedlo se otevrit soubor.");
        return 1;
    }
    Tpole * p = nactiSoubor(f);
    if (p == NULL) {
        perror("Neco se nepovedlo behem cteni vstupniho souboru");
        return 1;
    }

    vytiskniOpacne(stdout, p);

    fclose(f);
    uvolniPole(p);

    return 0;
}
