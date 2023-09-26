# Basic Data types and Variables
- global variable is stored in .exe file
    * local is not
- typedef = type specifier
    * is used for renaming Data types
- int (* x)[] = x je ukazatel na pole integeru
- void (*f)(void) = f je ukazatel na funkci bez parametr vracejici void
- int *f(void)[]
    * f is function without parameters returning array of pointers to int
    * In C language cannot be! Function cannot return array
        * because array cannot be assigned (and does not remeber it's length)

## Pointer types
- type pointer 
- variable pointer = contains address
- & = reference operator = find out address
- * = dereference operator = contains address and look where the pointer goes
- Tosoba a; - pamet si vyhradila bajty
- Tosoba * x;  - ma v sobe adresu (ale jeste niceho) - smeti
- x = NULL; - potreba udelat, abych byl to schopen testovat
- x = &a; - ma v sobe adresu a
- a.vek = 10;
- x->vek = 100; - zmeneno i v promene a
- dereferencni operator mi vrati to misto;
- *x.vek - zapis nemuze byt protoze . ma prednost pred *
- (*x).vek = 200; ---- x->vek = 200; - stejne
- L hodnota - *px += 5;
- R/P hodnota - &(1 + 2) - zapis nema smysl
- *a = odkazuje na misto s hodnotou - promenna s typem pointer
- &x = 10; - nejde protoze nemuze priradi adrese desitku 

