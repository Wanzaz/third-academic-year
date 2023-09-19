# Dynamicke datove struktury zasobnik, fronta

## Abstraktni datovy typ (ADT)
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
