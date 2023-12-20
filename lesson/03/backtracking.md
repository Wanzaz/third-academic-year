# Backtracking
- algoritmy prohledavani s navratem
    - nejde o vyhledavani v datech
- **Algoritmus prohledavani stavoveho prostoru**
- Kazda krizovatka je pomyslny uzel ve stromu

## Ulohy
- Motivacni bludiste - najdi cestu bludistem
- Uloha osmi dam - heuristika

# Bludiste - problemy
- Pri reseni je videt jen na konec chodby
- Dopredu nebyva jasne, jak je bludiste velke
- V bludisti lze chodit stale dokola (obsahuje cykly)
- Typove podobne problemy lze najit i u jinych uloh

# Bludiste - reseni
- Reseni hrubou silou
- Prohledavani s navratem (lepsi nez nahodne)
    - da se pouzit pri omezenem poctu uzlu

# Problem s cykly (nekonecna cesta -> nekonecna rekurze)
- Principi Adriadniny nite
- Od zacatku odvijime nit z klubka konecne delky
- Lepsi je jit ze zacatku do sirky a pak do hloubky (ne naopak)

# Heuristika
- Obecne jde o jakekoli opatreni, slouzici ke zlepseni vypoctu
- nelze je vymyslet algoritmicky - chce to napady, zkusenosti, kreativni mysleni
- nebude zkoumat reseni, ketere nema ceny zkoumat dal


