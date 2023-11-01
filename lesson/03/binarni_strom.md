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

