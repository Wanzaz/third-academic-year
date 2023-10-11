# Dynamicke datove struktury zasobnik, fronta

## Abstraktni datovy typ (ADT)
- duvod: chceme dalsi specificke vlasnosti (velke misto je jen bonus)
- uzivatelsky datovy typ, ktery nezavisi na sve implementaci
- priklad: linearni seznam, fronta, zasobnik, strom, ..
- ADT je definovan:
    1. Svym nazvem
    2. Mnozinou hodnot, kterych mohou nabyvat promenne
    3. Mnozinou operaci, ktere lze nad promennymi realizovat
- naznak OOP

## Dynamicka datova struktura
- **meni svou velikost** (pocet prvku)

```c
typedef struct _prvek Tprvek;

struct _prvek {
    Tdata data; // obecně datové položky
    Tprvek* dalsi; // ukazatel na další prvek
    //Tprvek* predchozi; // oboustranný seznam
    //Tprvek *levy, *pravy; // strom
};
```

## Zasobnik - LIFO (Last In First Out)
- hlavni vlastnost: **meni poradi prvku (otaci ho)**
- Tvori ho jednosmerne vazany seznam prvku
- Pocatecni prvek - vrchol (top)
- Rekurzivni definice:
    * Zasobnik je
        * Prazndy (ukazatel je na vrchol je NULL)
        * Vrchol obsahujici ukazatel na zbytek zasobniku (coz je taky zasobnik)

```c
typedef struct {
    Tprvek* vrchol;
    //int pocet; // servisní informace
} Tzasobnik;
```

- posledni prvek zasobniku (naspodu) ma prazdny ukazatel (slouzi jako zarazka)
- zakladni operace:
    1. Push 
    2. Pop
        * pom = z->vrchol
        * z->vrchol = pom->dalsi
        * free(pom)
    3. Top - vrati hodnotu vrcholu
- nepoustime uzivatele k vrchnimu prvku (Tprvek) - jinak si to sami posereme

## Fronta (Queue) - FIFO (First In First Out) - Buffer
- k cemu slouzi: aby se zachovalo poradi prichozich
- jednosmerne vazany seznam prvku
- Prvni prvek (**front**) - nejstarsi (prvne pridany)
- Posledni prvek (**back**) - posledne pridany
- POZOR!!! - sekvencni struktury musime prochazet postupne

```c
typedef struct {
    Tprvek* prvni;
    Tprvek* posledni;
    int delka; // servisni informace
} Tzasobnik;
```


## Fronta - operace
- Doporuceni: nesmime si odriznout vetev
- enqueue = vlozi hodnotu na konec fronty
```
   1. f->posledni->dalsi
    = novy

   2. f->posledni = novy
```
- dequeue = 

## Fronta - uloha
- servisni informace - kolik prvku jsme tam uz vlozili
- enqueue +1
- dequeue -1
- smazeme nejstarsi a vlozime novy
```c
neng(q, data, n)
{
    if (n >= q->delka) 
    { deq(q); }
    enq(q, data);
}
```

# Linearni seznam
- pri velkem mnozstvi prvku je to neobhajitelne (neda se pouzit)

# Fronta v poli
- **Kruhova indexace pomoci operace modulo**

