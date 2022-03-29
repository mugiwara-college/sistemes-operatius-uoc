# Instruccions d'ús

## Linux (Ubuntu)

Comprova en una terminal (Ctrl+Alt+F) que tens el gcc instal·lat

```console
gcc --version
```

Si no el tens instal·lat execusta aquesta comanda:

```console
sudo apt-get update && sudo apt-get install build-essential
```

Si ja el tens instal·lat executa aquesta comanda:

```console
gcc -Wall filename.c -o filename
```

Modifica "filename" pel nom del fitxer on tens el codi font escrit en C.