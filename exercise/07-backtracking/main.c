#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char ypozice[8];
    bool jevradku[8];
    bool jesikmozleva[15];
    bool jesikmozprava[15];
} TSach;

bool jeOhrozena(TSach plocha, char x, char y)
{
    if (plocha.jevradku[y] ||
        plocha.jesikmozleva[x + y] ||
        plocha.jesikmozprava[x - y + 7]) {

        return true;
    }

    return false;
}

void polozDamu(TSach plocha, char x, char y)
{
    // 0 znamena bez damy
    plocha.ypozice[x] = y + 1;

    plocha.jevradku[y] = true;

    plocha.jesikmozleva[x + y] = true;

    plocha.jesikmozprava[x - y + 7] = true;
}

void odeberDamu(TSach plocha, char x, char y)
{
    // 0 znamena bez damy
    plocha.ypozice[x] = 0;

    plocha.jevradku[y] = false;

    plocha.jesikmozleva[x + y] = false;

    plocha.jesikmozprava[x - y + 7] = false;
}

void vykresliReseni(TSach plocha, FILE *f)
{
    fprintf(f, "---------------------------------\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (plocha.ypozice[j] == 8 - i) {
                fprintf(f, "| * ");
            } else {
                fprintf(f, "|   ");
            }
        }
        fprintf(f, "|\n");
        fprintf(f, "---------------------------------\n");
    }
    /**
    ---------------------------------
    |   |   |   |   |   |   |   |   |
    --------------------------------- 
    **/
}

void zkusSloupec(TSach plocha, char x)
{
    for (int y = 0 ; y < 8; y++) {
        if (!jeOhrozena(plocha, x, y)) {
            polozDamu(plocha, x, y);

            if (x == 7) {
                vykresliReseni(plocha, stdout);
                printf("\n");
            } else {
                zkusSloupec(plocha, x + 1);
            } 

            odeberDamu(plocha, x, y);
        }
    }
}

int main(int argc, char *argv[])
{
    TSach plocha = {
        .ypozice = {0},
        .jevradku = {false},
        .jesikmozleva = {false},
        .jesikmozprava = {false},
    };

    zkusSloupec(plocha, 0);

    return 0;
}
