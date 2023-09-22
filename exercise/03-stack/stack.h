#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct _prvek Tprvek;

typedef struct _zasobnik Tzasobnik;

struct _prvek
{
    char hodnota;
    Tprvek *dalsi;

};

struct _zasobnik 
{
    Tprvek * vrchol;
    int vyska;
};


/* \brief Odstrani vrchol zasobniku a vrati jeho data
 *
 * \ param
 * \ param
 * \ return bool
 *
 */
Tzasobnik * zasInit(void);

void zasFree(Tzasobnik *z);

bool zasPush(Tzasobnik *z, char data);

bool zasPop(Tzasobnik *z, char *d);

bool zasIsEmpty(Tzasobnik *z);

bool zasTop(Tzasobnik *z, char *d);

#endif // STACK_H_INCLUDED
