#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
    int i, j = 0;
    int N = 3; // n files
    int M = 4; // m columnes
    int valor = 1;
    int **matrix;

    /* Demana espai per a un vector d'N punters, un per a cada fila */
    matrix = malloc(N * sizeof(int *));
    if (matrix == NULL)
        printf("Memòria no disponible");

    for (i = 0; i < N; i++)
    {
        /* Demana espai per a la fila i-èssima (M enters) */
        matrix[i] = malloc(M * sizeof(int));
        if (matrix[i] == NULL)
            printf("Memòria no disponible");
    }

    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
        {
            matrix[i][j] = valor++; /* Omple la matriu */
            printf("fila = %d columna = %d valor = %d logic address = %p \n", i + 1, j + 1, matrix[i][j], &matrix[i][j]);
        }

    for (i = 0; i < N; i++)
        free(matrix[i]); /* Allibera la fila i-èssima */

    free(matrix); /* Allibera el vector de punters */
}
