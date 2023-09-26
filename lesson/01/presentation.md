# Datove typy a promenne v C

## Datovy typ
- **Je to recept, pro vyrobu promenne**
- Je definovan:
    * nazvem
    * mnozinou hodnot
    * operacemi, ktere lze nad hodnotami provadet

## Promenna
- **Pojmenovana pametova bunka**
- ma prirazeny datovy typ
- muze se **menit** v prubehu zivota programu

## Deklarace promenne, typu, funkce
- **Syntakticka konstrukce (zavazek)**
- rika prekladaci: "Vem na vedomi, ze bude existovat promenna (typ, funkce) tohoto jmena a bude tohoto typu"
- nevytvari nic v pameti programu - pamatuje si to prekladac
- pr. deklarace funkce (hlavicka, prototyp) s deklaracemi parametru funkce
    * ```int mojeFce(FILE *a, int b);```

## Definice promenne
- Prikaz, ktery vyrobi promennou v pameti
- Lokalni, Globalni

## Inicializace promenne
- **Prvni prirazeni hodnoty**
- neinicializovane hodnoty maji nedefinovanou hodnotu (smeti)
- Promenne nekterych typu lze jako celek nastavit jenom pri inicializaci!
    * napr. pole
```
int pole[] = {1, 2, 3, 4, 5};
pole = {1, 2, 3, 4}; // TOHLE UZ NEJDE
```

### sizeof(Typ), sizeof(promenna)
- vraci pocet bajtu, ktere zabira promenna (daneho typu) v pameti

### typedef
- specifikator noveho jmena typu
- slouzi pro prejmenovani typu
