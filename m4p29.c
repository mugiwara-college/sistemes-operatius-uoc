#include <unistd.h>

/*
Instruccions d'ús:
1. Compila el programa (README.md)
2. Executa el programa (README.md)
3. Escriu utilitzant el teclat
4. Prem enter

El programa mostra per std out (0) el que li escrius per l'std in (1).

Per acabar l'execució prem Ctrl+C
*/

//Porcés comodí 
int main()
{
    char buff;
    int fi_in, fi_out;
    fi_out = 1;
    fi_in = read(0, &buff, 1);
    
    /*
    mentre l'entrada no trobi fi de fitxer,
    i no es produeixin errors d'accés:
    */
    while ((fi_in > 0) && (fi_out > 0))
    {
        fi_out = write(1, &buff, 1);
        fi_in = read(0, &buff, 1);
    }
}