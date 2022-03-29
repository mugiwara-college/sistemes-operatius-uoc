#include <windows.h>
#include <stdio.h>

#define MAX_SIZE 64

void panic(const char *miss)
{
    fprintf(stderr, "Error in %s\n", miss);
    ExitProcess(1);
}

//Alerta, aquest codi només funciona amb windows (winAPI), de moment, executa el programa sense arguments.
int main(int argc, char *argv[])
{
    HANDLE h_in, h_out;

    DWORD num_read, num_written;
    BOOL ret;
    char buf[MAX_SIZE];

    if (argc == 1)
    {
        h_in = GetStdHandle(STD_INPUT_HANDLE);
        if (h_in == INVALID_HANDLE_VALUE)
            panic("GetStdHandle");
    }
    else
    {
        //TODO: trobar la manera correcta de passar el primer argument de la funció CreateFile 
        h_in = CreateFile((LPCWSTR)argv[0], GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
        if (h_in == INVALID_HANDLE_VALUE)
            panic("CreateFile");
    }

    h_out = GetStdHandle(STD_OUTPUT_HANDLE);
    if (h_out == INVALID_HANDLE_VALUE)
        panic("GetStdHandle");

    while (1)
    {
        ret = ReadFile(h_in, (void *)buf, MAX_SIZE, &num_read, NULL);
        if (ret)
        {
            if (num_read > 0)
            {
                ret = WriteFile(h_out, (void *)buf, num_read, &num_written, NULL);
                if (!ret)
                    printf("WriteFile");
                if (num_read != num_written)
                    panic("Missing chars");
            }
            else
                break;
        }
        else
            panic("ReadFile");
    }
}