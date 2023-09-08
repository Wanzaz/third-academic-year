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
