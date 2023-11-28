# Binarni vyhledavaci strom (DDS)
- rychle vkladat a vyhledavani
- nejlepsi vyuziti pro - **asociativni pole** (slovnik v pythonu)
```
            _______
            |L | R| - vrchol (koren)
            -------
           /       \
        _______ _______
        |/ | \| |/ | \|
        ------- -------
        /     \ /     \
                    _______
                    |/ | \| - list 
                    -------
```
- asociativni par - **klic** a **data**
- kolize (5 Novaku v tel. seznamu) -> musime projit linearne |P|->|P|->|P|->|P|
- nejvetsi problem **DEGENEROVANY STROM** - kdyz vkladame predem serazena data do stromu
    - da se to vse na jednu stranu stromu (a je to pak linearni slozitost)
- **AVL** algoritmus - vyvazovane stromy
- (Tnode **node) - predavat ukazatel odkazem
- u rekurzivnich funkcich je parametrem **uzel** a ne cela struktura stromu!!!

## Pruchody stromu
- kdyz menime neco ->  Tuzel** uzel
- kdyz nemenime -> Tuzel* uzel

### Typy pruchodu stromem
1. InOrder - vypise to v poradi v jakem to je serazene (z leva do prava)
```c
void inOrder(Tuzel *u) {
    if (u == NULL) {
        return;
    }
    inOrder(u->levy);
    vypis(u->klic);
    inOrder(u->pravy);
}
```
1. preOrder - dobre pro vyhledavani
```c
void preOdder(Tuzel *u) {
    if (u == NULL) {
        return;
    }
    vypis(u->klic);
    preOrder(u->levy);
    preOrder(u->pravy);
}
```
1. postOrder - dobre pro ruseni stromu (ale nemusi byt)
```c
void postOrder(Tuzel *u) {
    if (u == NULL) {
        return;
    }
    postOrder(u->levy);
    postOrder(u->pravy);
    vypis(u->klic);
}
```
```
         4
       /   \
      2     7
     / \   / \ 
    1   3  5  8
   / \    / \    
             6
```
- **io**: 1, 2, 3, 4, 5, 6, 7, 8
- **preo**: 4, 2, 1, 3, 7, 5, 6, 8
- **posto**: 1, 3, 2, 6, 5, 8, 7, 4


## Operace
- Zruseni stromu
- Vlozeni klice
    - nejdrive vyhledat pak vlozit
    - vkladame na dno
    - duplicitni klice neakceptujeme

# Rekurzivni definice stromu
- bud to pradny strom (NULL)
- nebo je to korenovy prvek obsahujici odkazy na levy a pravy podstrom

# Klicova vlastnost stromu
- V leve casti stromu mensi prvky
- V prave casti stromu vetsi prvky

Otazky
- Deklaruj datovy typ pro realizaci binarniho vyhledavaciho stromu, v nemz budou klic i data textove retezce
```c
typedef struct _klic Tklic;
typedef struct _klic {
}

typedef struct _uzel Tuzel;
struct _uzel {
    char klic[20];
    char data[20];
    Tuzel *levy;
    Tuzel *pravy;
};

typedef struct _strom Tstrom;
struct _uzel {
    Tuzel *koren;
    int vaha;
};

```

- Napis funkci: klic bude retezek, datova vyska je float, osoba - napis prumernou vysku osoby
```c

int pocet(Tuzel* uzel)
{
    if (u == NULL) {
        return 0;
    }

    return 1 +
        pocet(uzel->levy) +
        pocet(uzel->pravy);
}

float soucet(Tuzel* uzel)
{
    if (u == NULL) {
        return 0.0;
    }

    return uzel->vyska +
           soucet(uzel->levy) +
           soucet(uzel->pravy);
}

float prumer (Tstrom* s)
{
    return soucet(s->koren)/pocet(s-koren);
}

```



