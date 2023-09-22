#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

int main()
{
    /* FILE * f1 = fopen("cviceni-pr5-03-data.html", "r"); */
    /* FILE * f2 = fopen("cviceni-pr5-03-data2.html", "r"); */

    Tzasobnik * z = zasInit();

    if (z == NULL) { 
        printf("ERROR: Nezvladlo incializovat zasobnik");
        return 0; 
    };

    zasPush(z, 'A');
    zasPush(z, 'B');
    zasPush(z, 'C');

    while (!zasIsEmpty(z)) {
        char prvek;
        if (zasPop(z, &prvek)) {
            printf("Odstranen prvek: %c\n", prvek);
        } else {
            printf("Zasobnik je prazdny, nemuzeme odstranit prvky.\n");
        }
    }

    zasFree(z);


    /* fclose(f1); */
    /* fclose(f2); */
}
