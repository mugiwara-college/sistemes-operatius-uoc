#include <stdio.h>
#include <stdlib.h>

int main()
{
    // A quin valor comença a iterar el bucle for
    int i = 0;
    // A partir de quin valor deixa d'iterar el bucle for
    int N = 5;
    // Reservem 5 vegades la mida del pointer *vector a la memòria
    int *vector = malloc(N * sizeof(*vector));

    // Si no s'ha pogut reservar memòria la funció malloc returna NULL, aleshores:
    if (vector == NULL)
    {
        printf("%s\n", "Memòria no disponible");
    }

    for (i = 0; i < N; i++)
    {
        vector[i] = i + 1;
        printf("iteració = %d valor vector = %d logic address = %p \n", i, vector[i], &vector[i]);
    }

    // Alliberem la memòria reservada pel nostre vector
    free(vector);

    // return 0 indica que el programa s'ha executat correctament
    return 0;
}