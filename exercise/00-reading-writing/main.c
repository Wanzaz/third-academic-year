/*
 * Projekt: pr5-cviko00-cteni-psani
 * Autor: Donald Kačer -- podepiš se sem (a taky přejmenuj název adresáře)
 * Datum: doplň
 *
 * Šablona školního projektu © 2021 David Martinek.
 *
 * Zadání:
 * 1. Zorientuj se v připraveném (nehotovém) programu.
 * 2. Doplň kód programu tak, aby vypsal data zadaného souboru v opačném pořadí.
 *
 * Formát vstupního souboru:
 * - Na prvním řádku je počet prvků, které následují.
 * - Na dalších řádcích jsou prvky - desetinná čísla (typ float).
 *
 * Formát výstupního souboru:
 * - stejný jako vstupní (včetně 1. řádku)
 * - tiskni na konzoli (stdout - standardní výstup)
 *
 * Použij připravený datový typ Tpole a hotové funkce novePole a uvolniPole.
 * Tyto funkce si prohlédni, ale znovu je nepiš - máš je pouze použít podle
 * návodu.
 *
 * Doplň kód funkcí main, nactiSoubor a vytiskniOpacne.
 *
 */

// Pár drobností pro zjednodušení práce - hlavičkový soubor můžeš prozkoumat.
/* #include "gvid.h" */
// Můžeš použít:
// dprintf() - jako printf, ale pro ladící účely
// vycistiKonzoli() - vyčistí konzoli
// uint - zkratka pro typ unigned int

#include <stdio.h>
#include <stdlib.h>
// #include <string.h>  // pro práci s textovými řetězci
#include <stdbool.h> // pro práci s typem bool a konstantami true a false
#include <ctype.h>   // isalpha, isspace, islower, isupper, ...
                     // #include <math.h>    // funkce z matematické knihovny
                     // #include <float.h>   // konstanty pro racionální typy DBL_MAX, DBL_DIG, ...
                     // #include <limits.h>  // konstanty pro celočíselné typy INT_MAX, INT_MIN, ...
                     // #include <time.h>    // funkce time a další pro práci s časem


                     ///////////////////////// DEKLARACE DATOVÉ STRUKTURY ///////////////////////////

/** Struktura zastřešující pole a údaj o jeho délce. */
typedef struct pole
{
    float *prvek;
    int delka;
} Tpole;

/*
   Pomocí připravených funkcí lze s typem pracovat takto:
   Tpole *q = novePole(5);  // Alokuje novou strukturu s polem délky 5 a vrátí na ni ukazatel.
   q->prvek[index]          // práce s prvkem pole
   q->delka                 // přístup k údaji o délce pole
   uvolniPole(q);           // Uvolní alokovanou paměť. (Očekává ukazate a q je ukazatel, proto bez &).

   Nápověda k práci s typem Tpole (v této úloze ale není potřeba s ním takto pracovat):
   Tpole p;          // Vyrobí neinicializované pole - je třeba ho alokovat.
   p.prvek[index]    // přístup k prvku pole
   p.delka           // přístup k údaji o délce pole
   */


///////////////////////// HLAVIČKY POMOCNÝCH FUNKCÍ ////////////////////////////

/** \brief Alokuje v paměti strukturu s polem o zadané délce. Bázovým typem pole je float.
 *
 * Pokud není dostatek paměti, vrací NULL.
 *
 * Poznámka: Funkce novePole - uvolniPole se používají analogicky párům funkcí
 * fopen - fclose a malloc - free.
 *
 * \param delka uint Požadovaný počet prvků pole.
 * \return Tpole Vrací ukazatel na novou strukturu s polem a skutečnou délkou.
 */
Tpole * novePole(int delka);

/** \brief Uvolní alokované pole z paměti.
 *
 * Pozor! Pokus o uvolnění již uvolněného pole může vést k havárii.
 *
 * \param pole Tpole* Ukazatel na strukturu s polem alokovanou funkcí novePole(). Parametr předávaný odkazem.
 */
void uvolniPole(Tpole *pole);


///////////////////////////// ŘEŠENÉ PODPROGRAMY ///////////////////////////////


/** \brief Načte data ze souboru do pole pomocí struktury Tpole.
 *
 * V souboru musí být na prvním řádku celé číslo udávající počet hodnot.
 *
 * Pokud je soubor vadný (například počet je <= 0) nebo není dost paměti pro
 * strukturu Tpole, funkce vrací NULL. Po použití funkce by se měl výsledek
 * otestovat (podobně jako po použití fopen).
 *
 * \param f FILE* Ukazatel na soubor otevřený pro čtení.
 * \return Tpole* Vrací ukazatel na strukturu s načteným polem nebo NULL.
 *
 */
Tpole *nactiSoubor(FILE *f)
{
    // TODO Načti počet prvků z prvního řádku souboru. Vrať NULL, když je něco špatně.
    int count;
    if (fscanf(f, "%d", &count) != 1) {
        // Failed to read the count, return NULL
        return NULL;
    }

    // TODO Vyrob pole (Tpole*). Když se to nepovede, vrať NULL.
    Tpole *p = novePole(count);
    if (p == NULL) {
        // Memory allocation failed, return NULL
        return NULL;
    }

    // Initialize the length and allocate memory for data
    p->delka = count;

    // TODO Čti prvky, nanejvýš tolik, kolik je uvedeno na 1. řádku souboru.
    // Když se nějaký prvek nepovede přečíst, uprav záznam o délce pole ve struktuře a vrať ji.
    for (int i = 0; i < count; i++) {
        if (fscanf(f, "%f", &(p->prvek[i])) != 1) {
            // Failed to read an element, adjust the length and return
            p->delka = i;
            return p;
        }
    }

    // TODO Vrať ukazatel na strukturu s přečteným polem (proměnnou typu Tpole *).
    return p;
}


/** \brief Vytiskne do souboru pole zabalené do struktury Tpole v opačném pořadí.
 *
 * Nejprve tiskne délku pole, až pak prvky pole v opačném pořadí, aby formát
 * odpovídal formátu ve vstupním souboru.
 *
 * Finta: Pro tisk na konzoli stačí při volání místo souboru zadat stdout.
 *
 * \param out FILE* Ukazatel na soubor otevřený pro zápis.
 * \param p Tpole*  Ukazatel na strukturu s polem.
 */
void vytiskniOpacne(FILE *out, Tpole * p)
{
    // TODO Vytiskni počet prvků pole.
    fprintf(out, "The amount of numbers in this file is: %d\n", p->delka);

    // TODO Vytiskni prvky pole od posledního k prvnímu.
    for (int i = p->delka - 1; i >= 0; i--) {
        fprintf(out, "%.2f\n", p->prvek[i]);
    }

}

////////////////////////////////// MAIN ////////////////////////////////////////

//int main(int argc, char *argv[])  // pro parametry příkazového řádku
int main(void)
{
    // TODO Zeptej se uživatele na cestu k souboru s daty.
    // Poznámka: V projektu máš připravený soubor data.txt, který použij pro
    // testování.
    // Pozor! Ve funkci scanf nesmíš použít značku %s - musíš ji omezit, aby
    // načetla maximálně 99 znaků, aby se to vešlo do proměnné cesta!
    char cesta[100];
    printf("Zadej cestu k souboru: ");
    scanf("%99s", cesta);



    // TODO Otevři soubor jehož název je uložen v proměnné cesta pro čtení.
    // Nezapomeň otestovat, zda se to povedlo.
    //FILE * f = fopen(...
    FILE * file = fopen(cesta, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1; // Exit with an error code
    }

    // TODO Načti soubor do pole pomocí své funkce nactiSoubor.
    // Nezapomeň otestovat, zda se to povedlo.
    // Tpole * p = ...
    Tpole * p = nactiSoubor(file);
    if (p == NULL) {
        perror("Something went wrong with reading the input file");
        return 1; // Exit with an error code
    }


    // TODO Vytiskni načtené pole v opačném pořadí pomocí funkce vytiskniOpacne.
    // Místo výstupního souboru použij stdout (proměnná ze stdio.h).
    vytiskniOpacne(stdout, p);


    // TODO Nakonec zavřít, uvolnit a odevzdat...
    fclose(file);
    uvolniPole(p);

    return 0;
}

///////////////////////// IMPLEMENTACE POMOCNÝCH FUNKCÍ ////////////////////////


Tpole * novePole(int delka)
{
    Tpole * sp = malloc(sizeof(Tpole));

    // Pokud se nepovedlo alokovat strukturu, vrátím NULL.
    if (sp == NULL)
        return NULL;

    sp->prvek = malloc(delka*sizeof(float));

    // Pokud se nepovedlo alokovat pole, vrátím NULL.
    if (sp->prvek == NULL)
    {
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
