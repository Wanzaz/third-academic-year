# Dynamicke datove struktury zasobnik, fronta

## Abstraktni datovy typ (ADT)
- duvod: chceme dalsi specificke vlasnosti (velke misto je jen bonus)
- priklad: linearni seznam, fronta, zasobnik, strom, ..
- ADT je definovan:
    1. Svym nazvem
    2. Mnozinou hodnot, kterych mohou nabyvat promenne
    3. Mnozinou operaci, ktere lze nad promennymi realizovat
- naznak OOP

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
