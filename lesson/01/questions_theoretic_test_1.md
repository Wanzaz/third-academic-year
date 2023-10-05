## Otazky 1 prezentace
- Proc OS vytvari programum model operacni pameti?
    * oddeli se nase prace a prace OS
    * pro ulehceni prace programatorum
    * ochrana pameti
- Proc se dynamicke pole neda vyrobit se zavorkami?
    * ```float p[10];``` - lokalni promenna na zasobniku
    * ```p``` je ukazatel na prvni prvek pole
    * ```float * q = p;```
    * ```q[i] = i * i;```
    * ```p = q;``` - nejde
    * na heapu nejde syntakticky vyrobit
    * kdyz pouziji malloc na heap tak to alokuje nejake misto ale nejde tam promenna
        * pracuje se jenom neprimo (indexovanim)
- Co se deje se spustitelnym souborem po spusteni?
    * program se da do datove a kodove casti
    * funkce si postupne alokuji misto...

## Odvozeni hlavicky funkce z parametru
```c
char fce(float a, long * b);

long y = 10;
char x = fce(5.3, &y);
```

## L - hodnota
- vyraz reprezentujici misto v pameti, kam lze zapisovat

## P - hodnota
- neni to promenna

## Feedback na testy - caste chyby
- void = procedura
- ```void fce(float a, float *a);``` - blbost protoze se dva parametry jmenuji stejne
- ```long * pole[]``` = pole ukazatelu na long
- ```long pole[]``` = staticke pole na zasobniku, lokalni pole typu pole
- ```long * pole``` = typu ukazatel, pribuzna poli
- ```long * pole = malloc()``` = typu ukazatel, pribuzna poli
- ```pole[i]``` = hvezdicku nahrazuji zavorky


