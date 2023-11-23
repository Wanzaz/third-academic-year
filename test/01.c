#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _prvek Tprvek;
struct _prvek{
    char data;
    Tprvek * dalsi;
};

typedef struct {
    Tprvek * vrchol;
}Tzasobnik;

typedef struct {
    Tprvek * prvni;
    Tprvek * posledni;
}Tfronta;

typedef struct {
    Tprvek * prvni;
    Tprvek * aktualni;
    Tprvek * posledni;
}Tseznam;

Tprvek * novyPrvek(char data)
{
    Tprvek * novy = malloc(sizeof(Tprvek));
    if(novy == NULL)
    {
        return NULL;
    }
    novy->data = data;
    novy->dalsi = NULL;
    return novy;
}

Tzasobnik * initZas()
{
    Tzasobnik * z = malloc(sizeof(Tzasobnik));
    if(z == NULL)
    {
        return NULL;
    }
    z->vrchol = NULL;
    return z;
}

Tfronta * initFr()
{
    Tfronta * f = malloc(sizeof(Tzasobnik));
    if(f == NULL)
    {
        return NULL;
    }
    f->prvni = NULL;
    f->posledni = NULL;
    return f;
}

Tseznam * initSez()
{
    Tseznam * s = malloc(sizeof(Tseznam));
    if(s == NULL)
    {
        return NULL;
    }
    s->prvni = NULL;
    s->posledni = NULL;
    s->aktualni = NULL;
    return s;
}

bool push(Tzasobnik * z, char data)
{
    Tprvek * p = novyPrvek(data);
    if(p == NULL)
    {
        return false;
    }
    p->dalsi = z->vrchol;
    z->vrchol = p;
    return true;
}

bool pop(Tzasobnik * z, char * data)
{
    if(z->vrchol == NULL)
    {
        return false;
    }
    *data = z->vrchol->data;
    Tprvek * pom = z->vrchol;
    z->vrchol = pom->dalsi;
    free(pom);
    return true;
}

bool enqueue(Tfronta * f, char data)
{
    Tprvek * p = novyPrvek(data);
    if(p == NULL)
    {
        return false;
    }
    if(f->posledni == NULL)
    {
        f->prvni = p;
    }
    else
    {
        f->posledni->dalsi = p;
    }
    f->posledni = p;
    return true;
}

bool dequeue(Tfronta * f, char * data)
{
    if(f->posledni == NULL)
    {
        return false;
    }
    *data = f->prvni->data;
    Tprvek * pom = f->prvni;
    f->prvni = pom->dalsi;
    free(pom);
    if(f->prvni == NULL)
    {
        f->posledni = NULL;
    }
    return true;
}

bool enqueueSez(Tseznam * s, char data)
{
    Tprvek * p = novyPrvek(data);
    if(p == NULL)
    {
        return false;
    }
    if(s->posledni == NULL)
    {
        s->prvni = p;
    }
    else
    {
        s->posledni->dalsi = p;
    }
    s->posledni = p;
    s->aktualni = s->posledni;
    return true;
}

bool popSez(Tseznam * s, char * data)
{
    if(s->prvni == NULL)
    {
        return false;
    }
    *data = s->prvni->data;
    Tprvek * pom = s->prvni;
    s->prvni = pom->dalsi;
    s->aktualni = pom->dalsi;
    free(pom);
    if(s->prvni == NULL)
    {
        s->posledni = NULL;
    }
    return true;
}

bool insert(Tseznam * s, char data)
{
    if(s->aktualni == s->posledni)
    {
        return enqueueSez(s, data);
    }
    else
    {
        Tprvek * p = novyPrvek(data);
        if(p == NULL)
        {
            return false;
        }
        p->dalsi = s->aktualni->dalsi;
        s->aktualni->dalsi = p;
        s->aktualni = p;
        return true;
    }
}

bool removeNext(Tseznam * s, char * data)
{
    if(s->aktualni == NULL)
    {
        return false;
    }
    if(s->aktualni == s->prvni)
    {
        return popSez(s, data);
    }
    else if(s->aktualni == s->posledni)
    {
        return false;
    }
    else
    {
        *data = s->aktualni->dalsi->data;
        Tprvek * pom = s->aktualni->dalsi;
        s->aktualni->dalsi = pom->dalsi;
        free(pom);
        if(s->aktualni->dalsi == NULL)
        {
            s->posledni = NULL;
        }
        return true;
    }
}

void zasFree(Tzasobnik * z)
{
    char a;
    while(pop(z, &a));
    free(z);
}

void frFree(Tfronta * f)
{
    char a;
    while(dequeue(f, &a));
    free(f);
}

void sezFree(Tseznam * s)
{
    char a;
    s->aktualni = s->prvni;
    while(removeNext(s, &a));
    free(s);
}

bool currentData(Tseznam * s, char * a)
{
    if(s->aktualni == NULL)
    {
        return false;
    }
    else
    {
        *a = s->aktualni->data;
        return true;
    }
}

int pocet(Tzasobnik * z)
{
    int i = 0;
    Tprvek * pom = z->vrchol;
    while(pom != NULL)
    {
        i++;
        pom = pom->dalsi;
    }
    return i;
}

void zmenPrvky(Tzasobnik * z)
{
    Tprvek * pom = z->vrchol;
    while(pom != NULL)
    {
        pom->data = pom->data *2;
        pom = pom->dalsi;
    }
}

void projedPrvky(Tzasobnik * z)
{
    Tprvek * pom = z->vrchol;
    while(pom != NULL)
    {
        printf("%d\n", pom->data);
        pom = pom->dalsi;
    }
}

bool seznamNext(Tseznam * s)
{
    if(s->aktualni == s->posledni)
    {
        return false;
    }
    else
    {
        s->aktualni = s->aktualni->dalsi;
        return true;
    }
}

void projedSeznam(Tseznam * s)
{
    while(seznamNext(s) == true)
    {
        printf("%d\n", s->aktualni->data);
    }
}

bool fce(FILE * in)
{
    Tzasobnik * z = initZas();
    if(z == NULL)
        return false;
    char x, x2;
    while(fscanf(in, "%c", &x) == 1)
    {
        if(x != '*')
        {
            printf("%c", x);
        }
        else
        {
            printf("%c", x);
            while(fscanf(in, "%c", &x) == 1 && x != '*')
            {
                if(!push(z, x))
                    return false;
            }
            /* x2 = x; */
            /* if(x != '*') */
            /* { */
            /*     if(!pop(z, &x)) */
            /*         return false; */
            /* } */
            while(pop(z, &x) == true)
            {
                printf("%c", x);
            }
            /* printf("%c", x2); */
            printf("*");
        }
    }
    return true;
}

int main()
{
    char soubor[20];
    printf("Zadej nazev souboru: ");
    scanf("%19s", soubor);
    FILE * f = fopen(soubor, "r");
    if(f == NULL)
    {
        printf("Chyba v nacteni souboru");
        return EXIT_FAILURE;
    }
    if(!fce(f))
        printf("Funkce se nepovedla");
    fclose(f);
    return 0;
}
