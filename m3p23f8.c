#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

void err_n_as_array_index_mes_gran_o_igual();
void err_buffer_overflow();
int *err_ref_vars_despres_de_return();
int *rut();
void err_access_memoria_alliberada();

int main()
{

    /* Error de programació si n >= 10 */
    err_n_as_array_index_mes_gran_o_igual();

    /* Error de programació perquè la memòria intermèdia s és massa petita (buffer overflow) */
    err_buffer_overflow();

    /* Error de programació perquè no té sentit referenciar variables locals d'un procediment un cop aquest ha acabat */
    err_ref_vars_despres_de_return();

    /* Error de programació perquè s'accedeix a memòria alliberada */
    err_access_memoria_alliberada();

    return 0;
}

void err_n_as_array_index_mes_gran_o_igual()
{
    int vector[10];
    vector[11] = 0;
}

int *err_ref_vars_despres_de_return()
{
    int *k;
    int n;
    n = 10;
    return (&n);

    k = rut();
    n = *k;
}

int *rut()
{
    int r;
    r = 1;
    return (&r);
}

void err_buffer_overflow()
{
    int vector[10];
    char s[10];
    sprintf(s, "El valor de vector[3] és %d\n", vector[3]);
}

void err_access_memoria_alliberada()
{
    char *p;
    p = malloc(100);
    free(p);
    p[4] = 'c';
}