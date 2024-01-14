#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char ypozice[8];
    bool jevradku[8];
    bool jesikmozleva[15];
    bool jesikmozprava[15];
} TSach;

/* typedef struct _prvek TPrvek; */

/* typedef struct _prvek { */
/*     char hodnota[8]; */
/*     TPrvek* dalsi; */
/*     TPrvek* predchozi; */
/* } TPrvek; */

/* typedef struct { */
/*     TPrvek* aktualni; */
/*     int pocet; */
/*     int index; */
/* } TReseni; */


/* TReseni* seznamInit(void) */
/* { */
/*     TReseni* seznam = malloc(sizeof(TReseni)); */
/*     if (seznam == NULL) { */
/*         return NULL; */
/*     } */

/*     seznam->aktualni = NULL; */
/*     seznam->pocet = 0; */
/*     seznam->index = -1; */
/*     return seznam; */
/* } */

/* bool vlozitDoSeznamu(TReseni* reseni, char poziceDam[8]) */
/* { */
/*     TPrvek* prvek = malloc(sizeof(TPrvek)); */   
/*     if (prvek == NULL) { */
/*         return false; */
/*     } */

/*     for (int i = 0 ; i <= 7; i++) { */
/*         prvek->hodnota[i] = poziceDam[i]; */
/*     } */
/*     if (reseni->aktualni == NULL) { */
/*         prvek->dalsi = prvek; */
/*         prvek->predchozi = prvek; */
/*         reseni->index = 0; */
/*     } else { */
/*         prvek->dalsi = reseni->aktualni->dalsi; */
/*         reseni->aktualni->dalsi = prvek; */
/*         prvek->predchozi = reseni->aktualni; */
/*         reseni->aktualni += 1; */
/*     } */

/*     reseni->aktualni = prvek; */
/*     return true; */
/* } */

/* bool zrusitPrvek(TReseni* reseni, char data[8]) */
/* { */
/*     if (reseni->aktualni == NULL) { */
/*         return false; */
/*     } */
/*     TPrvek* prvek = reseni->aktualni; */
/*     *data = prvek->hodnota; */
/*     if (prvek->dalsi == prvek) { // its single-item queue */
/*         free(prvek); */
/*         reseni->aktualni = NULL; */
/*         reseni->pocet = 1; */
/*         return true; */
/*     } */

/*     prvek->predchozi->dalsi = prvek->dalsi; */
/*     prvek->dalsi->predchozi = prvek->predchozi; */
/*     reseni->aktualni = prvek->dalsi; */
/*     free(prvek); */
/*     reseni->pocet += 1; */
/*     return true; */
/* } */

/* void zrusitSeznam(TReseni* reseni) */
/* { */
/*     char pom; */
/*     while (zrusitSeznam(reseni, &pom)) {} */

/*     free(reseni); */
/* } */

bool jeOhrozena(TSach plocha, char x, char y)
{
    if (plocha.jevradku[y] ||
        plocha.jesikmozleva[x + y] ||
        plocha.jesikmozprava[x - y + y]) {

        return true;
    }

    return false;
}

void polozDamu(TSach plocha, char x, char y)
{
    // 0 znamena bez damy
    plocha.ypozice[x] = y + 1;

    plocha.jevradku[y] = true;

    plocha.jesikmozleva[x + y] = true;

    plocha.jesikmozprava[x - y + 7] = true;
}

void odeberDamu(TSach plocha, char x, char y)
{
    // 0 znamena bez damy
    plocha.ypozice[x] = 0;

    plocha.jevradku[y] = false;

    plocha.jesikmozleva[x + y] = false;

    plocha.jesikmozprava[x - y + 7] = false;
}

/* void zapamatuj(TReseni* reseni, TSach plocha) */
/* { */
/*     vlozitDoSeznamu(reseni, plocha.ypozice); */
/* } */

/* void zkusSloupec(TReseni* reseni, TSach plocha, char x) */
/* { */
/*     for (int y = 0 ; y <= 7; y++) { */
/*         if (!jeOhrozena(plocha, x, y)) { */
/*             polozDamu(plocha, x, y); */
/*         } */

/*         if (x == 7) { */
/*             zapamatuj(reseni, plocha); */
/*         } else { */
/*             zkusSloupec(reseni, plocha, x + 1); */
/*         } */

/*         odeberDamu(plocha, x, y); */
/*     } */
/* } */

void vykresliReseni(TSach plocha, FILE *f)
{
    fprintf(f, "---------------------------------\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (plocha.ypozice[j] == 8 - i) {
                fprintf(f, "| * ");
            } else {
                fprintf(f, "|   ");
            }
        }
        fprintf(f, "|\n");
        fprintf(f, "---------------------------------\n");
    }
    /**
    
    **/
}

void zkusSloupec(TSach plocha, char x)
{
    for (int y = 0 ; y < 8; y++) {
        if (!jeOhrozena(plocha, x, y)) {
            polozDamu(plocha, x, y);

            if (x == 7) {
                vykresliReseni(plocha, stdout);
                printf("\n");
            } else {
                zkusSloupec(plocha, x + 1);
            } 

            odeberDamu(plocha, x, y);
        }
    }
}

/* zapamatuj(reseni, plocha); */
/* for (int i = 0; i < 8; i++) { */
/*     printf("%c", plocha.ypozice[i]); */
/* } */


int main(int argc, char *argv[])
{
    // inicializace seznamu reseni
    /* TReseni *reseni = seznamInit(); */

    /* zkusSloupec(reseni, plocha, 0); */

    /* vykresliReseni(plocha, stdout); */

    TSach plocha = {
        .ypozice = {0},
        .jevradku = {false},
        .jesikmozleva = {false},
        .jesikmozprava = {false},
    };

    zkusSloupec(plocha, 0);

    return 0;
}

