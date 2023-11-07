# Napis program
```c
void vypisOpacne(File *vstup) {
    Tz* z = zasInit();

    char pom;
    while(fscanf(vstup, "%c", &pom) == 1) {
        zasPush(z, pom);
    }

    while(zasPop(z, &pom)) {
        printf("%c\n", pom);
    }

    zasFree(z);
}
```
