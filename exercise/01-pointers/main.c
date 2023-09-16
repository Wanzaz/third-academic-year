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

    // Pokud se nepovedlo alokovat strukturu, vrátím NULL.
    if (sp == NULL) {
        return NULL;
    }

    sp->prvek = malloc(delka*sizeof(float));

    // Pokud se nepovedlo alokovat pole, vrátím NULL.
    if (sp->prvek == NULL) {
        free(sp); // nezapomeň uvolnit už vyrobenou strukturu
        return NULL;
    }

    sp->delka = delka;
    return sp;
}

void uvolniPole(Tpole *p)
{
    // Uvolní dynamicky alokované pole z paměti.
    free(p->prvek);

    free(p);
}

Tpole *nactiSoubor(FILE *f)
{
    // TODO Načti počet prvků z prvního řádku souboru. Vrať NULL, když je něco špatně.
    int pocet = 0;
    if (fscanf(f, "%i", &pocet) != 1) {
        return NULL;
    }

    // TODO Vyrob pole (Tpole*). Když se to nepovede, vrať NULL.
    Tpole *p = novePole(pocet);
    if (p == NULL) {
        return NULL;
    }

    // TODO Čti prvky, nanejvýš tolik, kolik je uvedeno na 1. řádku souboru.
    // Když se nějaký prvek nepovede přečíst, uprav záznam o délce pole ve struktuře a vrať ji.
    for (int i = 0; i < pocet; i++) {
        if (fscanf(f, "%f", &(p->prvek[i])) != 1) {
            // Failed to read an element, adjust the length and return
            p->delka = i;
            return p;
        }
    }

    // TODO Vrať ukazatel na strukturu s přečteným polem (proměnnou typu Tpole *).
    return p;
}

float prumernaHodnota(Tpole *p)
{
    int i;
    float soucet = 0;

    for (i = 0; i < p->delka; ++i) {
        soucet += p->prvek[i];
    }

    return soucet / i;
}

/*NEVYPISUJE POCET NA ZACATKU SOUBORU*/
/* void rozdel(FILE *f1, FILE *f2, Tpole *p, float hranice) */
/* { */
/*     for (int i = 0; i < p->delka; ++i) { */
/*         FILE *soubor = p->prvek[i] < hranice ? f1 : f2; */
/*         fprintf(soubor, "%f \n", p->prvek[i]); */
/*     } */
/* } */

void vytiskni(FILE *out, Tpole * p)
{
  fprintf(out, "%i\n", p->delka);

  for (int index = 0; index < p->delka; index++) {
      fprintf(out, "%f\n", p->prvek[index]);
  }
}

void rozdel(FILE *f1, FILE *f2, Tpole *p, float hranice)
{
    Tpole *mensi = novePole(p->delka);
    if (mensi == NULL) {
        return;
    }
    int mensi_pocet = 0;

    Tpole *vetsi = novePole(p->delka);
    if (vetsi == NULL) {
        return;
    }
    int vetsi_pocet = 0;

    for (int index = 0; index < p->delka; index++) {
        if (p->prvek[index] >= hranice) {
            vetsi->prvek[vetsi_pocet] = p->prvek[index];
            vetsi_pocet++;
            continue;
        }
        mensi->prvek[mensi_pocet] = p->prvek[index];
        mensi_pocet++;
    }

    mensi->delka = mensi_pocet;
    vetsi->delka = vetsi_pocet;
    vytiskni(f1, mensi);
    vytiskni(f2, vetsi);

    uvolniPole(mensi);
    uvolniPole(vetsi);
}

int main(void)
{
    char vstupniCesta[100];
    char vystupniCesta1[100];
    char vystupniCesta2[100];
    printf("Zadej cestu k vstupnimu souboru: ");
    scanf("%99s", vstupniCesta);
    printf("Zadej cestu k prvnimu vystupnimu souboru: ");
    scanf("%99s", vystupniCesta1);
    printf("Zadej cestu k druhemu vystupnimu souboru: ");
    scanf("%99s", vystupniCesta2);


    FILE * f = fopen(vstupniCesta, "r");
    if (f == NULL) {
        perror("Nepovedlo se otevrit soubor.");
        return 1;
    }

    FILE * fPodPrumer = fopen(vystupniCesta1, "w");
    if (fPodPrumer == NULL) {
        perror("Nepovedlo se otevrit soubor.");
        return 1;
    }

    FILE * fNadPrumer = fopen(vystupniCesta2, "w");
    if (fNadPrumer == NULL) {
        perror("Nepovedlo se otevrit soubor.");
        return 1;
    }

    Tpole * p = nactiSoubor(f);
    if (p == NULL) {
        perror("Neco se nepovedlo behem cteni vstupniho souboru");
        return 1;
    }

    float prumer = prumernaHodnota(p);
    printf("Prumer souboru je: %f", prumer);
    rozdel(fPodPrumer, fNadPrumer, p, prumer);


    fclose(f);
    fclose(fPodPrumer);
    fclose(fNadPrumer);
    uvolniPole(p);

    return 0;
}
