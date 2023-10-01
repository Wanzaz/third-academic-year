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

## Fronta (Queue) - FIFO (First In First Out)
- k cemu slouzi: aby se zachovalo poradi prichozich
- jednosmerne vazany seznam prvku
- Prvni prvek (**front**) - nejstarsi (prvne pridany)
- Posledni prvek (**back**) - posledne pridany

```c
typedef struct {
    Tprvek* prvni;
    Tprvek* posledni;
    int delka; // servisni informace
} Tzasobnik;
```

## Fronta - operace
- enqueue = vlozi hodnotu na konec fronty
- dequeue = 