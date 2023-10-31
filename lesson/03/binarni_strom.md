# Binarni strom (DDS)
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
