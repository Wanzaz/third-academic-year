/*
 * Projekt: Binární vyhledávací strom
 * Autor: David Martinek
 * Datum: 2020-11-11
 * Popis
 * Implementace funkcí realizující binární vyhledávací strom.
 */
#include <stdio.h>
#include <stdlib.h>
#include "strom.h"

// Tohle uživatel vidět nemusí. Ještě by mi do toho vlezl a něco mi tu poničil.
struct _tuzel
{
    int klic;           //< Klíč pro vyhledávání -- zde celé číslo
    float data;         //< Data vázaná na klíč -- zde desetinné číslo
    Tuzel* levy;   //< Ukazatel na levý podstrom
    Tuzel* pravy;  //< Ukazatel na pravý podstrom
};



Tstrom *bvsInit(void)
{
    Tstrom* strom = malloc(sizeof(Tstrom));
    if (strom == NULL)
    {
        return NULL;
    }

    strom->koren = NULL;
    strom->vaha = 0;
    return strom;
}

void _bvsZrus(Tuzel *u)
{
    if (u == NULL) return;
    _bvsZrus(u->levy);
    _bvsZrus(u->pravy);
    free(u);
}

void bvsZrus(Tstrom *strom)
{
    _bvsZrus(strom->koren);
    free(strom);
}


bool bvsJePrazdny(Tstrom *strom)
{
    return strom->koren==NULL;
}

int bvsVaha(Tstrom* strom)
{
    return strom->vaha;
}


Tuzel *_novyUzel(int klic, float data)
{
    Tuzel *u = malloc(sizeof(Tuzel));
    if (u == NULL) return NULL;
    u->klic = klic;
    u->data = data;
    u->levy = u->pravy = NULL;
    return u;
}

bool _bvsVloz(Tuzel **u, int klic, float data)
{
    Tuzel* pom = *u; // pomucka pro eliminaci *, POZOR!!!
    
    if (pom == NULL) {
        if ((pom = _novyUzel(klic, data)) == NULL) { return false; }

        *u = pom; // NUTNE!!! pom je lokalni
        return true;
    }
    // nevkladame nahodou duplicitni klic? ne nevkladamae protoze tady si
    // na duplicitni klice nehrajeme
    //if (klic == pom->klic) return false
    
    // patri v levo nebo pravo
    /* if (klic < pom->klic) { */
    /*     return _bvsVloz(&pom->levy, klic, data); */
    /* } else { */
    /*     return _bvsVloz(&pom->pravy, klic, data); */
    /* } */
    
    // lepsi zapsani swag
    return _bvsVloz(klic < pom->klic ? &pom->levy : &pom->pravy, klic, data);
}

bool bvsVloz(Tstrom *strom, int klic, float data)
{
    if (_bvsVloz(&strom->koren, klic, data))
    {
        strom->vaha += 1;
        return true;
    }
    return false;
}

/** Zruší zadaný uzel. */
bool _zrusUzel(Tuzel **uzel)
{
    Tuzel *pom = *uzel;
    
    if (pom == NULL) { return false; }

    if (pom->levy == NULL) {
        *uzel = pom->pravy;
        free(pom);

        return true;
    }

    if (pom->pravy == NULL) {
        *uzel = pom->levy;
        free(pom);

        return true;
    }

    if (pom->levy->pravy == NULL) {
        pom->klic = pom->levy->klic;

        return _zrusUzel(&pom->levy);
    }

    pom = pom->levy;
    while (pom->pravy->pravy != NULL) {
        pom = pom->pravy;
    }

    (*uzel)->klic = pom->pravy->klic;
    return _zrusUzel(&pom->pravy);
}

bool _bvsOdeber(Tuzel **u, int klic)
{
    Tuzel *uzel = *u;
    if (uzel == NULL) return false;
    if (klic == uzel->klic)
    {
        _zrusUzel(u); // tady se předává odkazem, i když to tak nevypadá! u se změní
        return true;
    }
    else if (klic < uzel->klic)
        return _bvsOdeber(&uzel->levy, klic);
    else
        return _bvsOdeber(&uzel->pravy, klic);
}


bool bvsOdeber(Tstrom *strom, int klic)
{
    if (_bvsOdeber(&strom->koren, klic))
    {
        strom->vaha -= 1;
        return true;
    }
    return false;
}


/** Pomocna funkce pro tisk stromu. */
unsigned int _bvsPom1(Tuzel *u)
{
    return (u == NULL)? 0 : _bvsPom1(u->levy) + _bvsPom1(u->pravy) + 1;
}


/** Pomocna funkce pro tisk stromu. */
unsigned int _bvsPom2(Tuzel *u)
{
    if (u == NULL)
        return 0;
    else
    {
        unsigned int a = _bvsPom2(u->levy);
        unsigned int b = _bvsPom2(u->pravy);
        return 1 + ((a > b)? a:b);
    }
}


/**
 * Pomocná funkce sloužící k ladícímu výpisu binárního stromu.
 * Do pole uzly uloží ukazatele na uzly ve správném pořadí podle klíčů.
 * Do pole uroven vloží úroveň, ve které se nachází uzel z pole uzly.
 */
void _stromNaPole(Tuzel *uzel, Tuzel *uzly[], unsigned int uroven[], int *index, int vyska)
{
    if (uzel == NULL) return;
    _stromNaPole(uzel->levy, uzly, uroven, index, vyska+1);
    uzly[*index] = uzel;
    uroven[*index] = vyska;
    (*index)++;
    _stromNaPole(uzel->pravy, uzly, uroven, index, vyska+1);
}


/**
 * Vytiskne hodnoty uložené ve stromu tak, že každou úroveň stromu vytiskne
 * na jeden řádek. Použitelné pro ladící účely. Pozor! Strom musí být ve
 * stavu, kdy se jím dá bezpečně procházet. Pokud listy nemají své podstromy
 * nastaveny na NULL, ale jsou v nich náhodné adresy, skončí tato operace
 * havárií.
 */
void bvsTisk(Tstrom *strom)
{
    if (strom->koren == NULL)
    {
        printf("NULL\n");
        return;
    }
    printf("\n\n");
    unsigned int mm = _bvsPom1(strom->koren);
    unsigned int nn = _bvsPom2(strom->koren);

    Tuzel *uzly[mm];
    unsigned int uroven[mm];
    int index = 0;

    _stromNaPole(strom->koren, uzly, uroven, &index, 0);

    for (unsigned int u = 0; u < nn; u++)
    {
        printf("Uroven %2d: ", u);
        for(unsigned int i = 0; i < mm; i++)
        {
            if(uroven[i] == u)
            {
                printf("%s[%4d]%s",
                        (uzly[i]->levy == NULL)? "|-" : "<-",
                        uzly[i]->klic,
                        (uzly[i]->pravy == NULL)? "-|" : "->");
            }
            else
            {
                printf("          ");
            }
        }
        printf("\n");
    }
}

int _vaha(Tuzel * u)
{
    if (u == NULL) { return 0; }

    return 1 + _vaha(u->levy) + _vaha(u->pravy);

}

int bvsPruchodVaha(Tstrom * strom)
{
    return _vaha(strom->koren);
}

void _preOrder(Tuzel * u)
{
    if (u == NULL) { return; }

    printf("%d - %f\n", u->klic, u->data);
    _preOrder(u->levy);
    _preOrder(u->pravy);
}

void vypisPreOrder(Tstrom * strom)
{
    _preOrder(strom->koren);
}

void _postOrder(Tuzel * u)
{
    if (u == NULL) { return; }

    _postOrder(u->levy);
    _postOrder(u->pravy);
    printf("%d - %f\n", u->klic, u->data);
}

void vypisPostOrder(Tstrom * strom)
{
    _postOrder(strom->koren);
}

void _inOrder(Tuzel * u)
{
    if (u == NULL) { return; }

    _inOrder(u->levy);
    printf("%d - %f\n", u->klic, u->data);
    _inOrder(u->pravy);
}

void vypisInOrder(Tstrom * strom)
{
    _inOrder(strom->koren);
}
