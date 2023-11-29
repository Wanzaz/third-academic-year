# Napis program
```c
void vypisOpacne(FILE *vstup) {
    Tz* z = zasInit();

    char pom;
    while(fscanf(vstup, "%c", &pom) == 1) {
        zasPush(z, pom);
    }

    while(zasPop(z, &pom)) {
        printf("%c\n", pom);
    }

    zasFree(z);
}
```

# 4 zkouseni
1. Deklaruj Tfronta a spocitej v ni prvky
```c
typedef struct {
    Tprvek* prvni;
    Tprvek* posledni;
    int pocet;
} Tfronta;

int spocitejPrvky(Tfronta *f)
{
    int i = 0;
    for(Tprvek* pom = f->prvni; pom!=NULL; pom = pom->dalsi) {
        i++
    }

    return i;
}
```
2. Deklaruj Tfronta a spoj dve fronty
```c
typedef struct {
    Tprvek* prvni;
    Tprvek* posledni;
    int pocet;
} Tfronta;

void spojDveFronty(Tfronta *f1, Tfronta *f2)
{
    for(Tprvek* pom = f2->prvni; pom!=NULL; pom = pom->dalsi) {
        enqueue(f1, pom->hodnota);
    }
}
```
3. Deklaruj Tzasobnik a udelej zasPush
```c
typedef struct {
    Tprvek* vrchol;
    int vyska;
} Tzasobnik;

bool zasPush(Tzasobnik *z, int data)
{
    Tprvek *novy = malloc(sizeof(Tprvek));
    if (novy == NULL) {
        return false;
    }

    novy->hodnota = data;

    novy->dalsi = z-vrchol;
    z-vrchol = novy;
    vyska++;

    return true
}
```
4. Deklaruj Tzasobnik a udelej zasPop
```c
typedef struct {
    Tprvek* vrchol;
    int vyska;
} Tzasobnik;

bool zasPush(Tzasobnik *z, int *data)
{
    if (z->vrchol == NULL) {
        return false;
    }

    Tprvek *pom = z-vrchol;
    *data = pom->hodnota;
    z->vrchol = pom->dalsi;
    free(pom)
    vyska--;

    return true
}
```

5. Mas na vstupu znaky a vypis je opacne
```c
void vypisOpacne(FILE *vstup) {
    Tz* z = zasInit();
    if (z == NULL) {
        return;
    }

    char pom;
    while(fscanf(vstup, "%c", &pom) == 1) {
        zasPush(z, pom);
    }

    while(zasPop(z, &pom)) {
        printf("%c\n", pom);
    }

    zasFree(z);
}
```
