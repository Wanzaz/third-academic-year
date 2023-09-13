# Dynamicka alokace pameti

## Operacni pamet
- kod programu + promenne (jsou v .exe souboru)

## Model operacni pameti
1. **Kodova oblast** - kod programu
2. **Datova oblast** - konstanty, globalni a staticke promenne
3. **Zasobnik** - stack - lokalni promenne a parametry funkci
4. **Hromada** - heap - o prideleni je nutne pozadat operacni system
    * muzeme alokovat mnohem vetsi prostor
    * operacni system nam rekne jestli muze pridelit prostor nebo ne
- int * p = malloc(kolikB) 
- void *malloc(size_t velikost)
    * #include <stdlib.h>
    * vzdy pouzivejte sizeof!!!
    * vraci adresu nebo NULL
        * testovat!!!
        * void* jde v C priradit do typoveho ukazatele bez pretypovani

## Dynamicka alokace jedne promenne
```
float* px = malloc(sizeof(float)); // alokace
if (px == NULL) { // test
    printf("Neni dost pameti!"); return NENI_PAMET;
}

// nejake vypocty s *px
*px = 1 + 1;
printf("Vysledek je %f.", *px); 

// ale operatory se vyrusi, takze se tam nemusi davat a muze byt jen px
scanf("%f", &*px) 

free(px); // dealokace
```

## Dynamicka alokace pole
```
float* pole = malloc(N * sizeof(float)); // alokace
if (pole == NULL) { // test
    printf("Neni dost pameti!"); return NENI_PAMET;
}

// nejake vypocty s  promennou pole
ole[0] = 543.35;
for (int i = 1; i < N; ++i) pole[i] = pole[i - 1] * 1.5;
printf("Vysledek je %f.", pole[N - 1]); 

free(pole); // dealokace
```

## Dynamicka alokace jedne struktury
```
Tosoba* o = malloc(sizeof(Tosoba)); // alokace
if (px == NULL) { // test
    printf("Neni dost pameti!"); return NENI_PAMET;
}

// nejake vypocty s promennou o
// ..
printf("Osoba se jmenuje %s.", i,  o->jmeno); 

free(px); // dealokace
```

## Dynamicka alokace pole struktury
```
Tosoba* o = malloc(N * sizeof(Tosoba)); // alokace pole osob
if (px == NULL) { // test
    printf("Neni dost pameti!"); return NENI_PAMET;
}

// nejake vypocty s promennou o
// ..
printf("%d. Osoba se jmenuje %s.", i,  o[i].jmeno); // POZOR kazdy prvek pole je osoba

free(px); // dealokace
```

## Realokace pameti
- Realokovavat po blocich jedine
    * jinak by se to pole mohlo porad prekopirovavat a byla by to silena algoritmicka slozitost

