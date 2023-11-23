- cely vstupni soubor otocit naruby
```c
void test1(FILE* in, FILE* out)
{
    int znak; // FGETC ---- INT
    // FSCANF ---- CHAR
    Tz * z = zasInit();
    while ((znak = fgetc(in)) != EOF) {
        zasPush(z, znak)
    }

    char pom;
    while (zasPop(z, &pom)) {
        fprintf(out, "%c", pom);
    }

    zasFree(z);
}
```

- cteme soubor schovana cisla a vytiskneme ciselny kod nejprve
```c
void test2(FILE* in, FILE* out)
{
    char znak;
    Tq * f = queueInit();
    while (fscanf(in, "%c", &znak) == 1) {
        if (znak >= '0' && znak <='9') { 
            fprintf(out, "%c", znak);
            continue;
        }
        enqueue(f, znak);
    }

    for (Tprvek pom = f->first; pom != NULL; pom = pom->dalsi) {
        fprintf(out, "%c", pom->value);
    }

    qFree(z);
}

```
