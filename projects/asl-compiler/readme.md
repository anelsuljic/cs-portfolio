# Projecte CL - ASL

Aquest repositori conté els fitxers de desenvolupament del projecte de l'assignatura Compiladors, del grau en enginyeria informàtica a la Facultat d'Informàtica de Barcelona, UPC. 

El projecte consisteix en desenvolupar un compilador del llenguatge de programació ASL. Més informació a la [web de l'assignatura](https://www.cs.upc.edu/~cl/).

El fitxer `tars/projecte-base.tgz` conté els fitxers base del projecte. Al descomprimir-lo cal modificar el Makefile de la següent manera:

A la part on apareix el següent:

```
# The root directory of your antlr4 runtime is ...
#ANTLR_ROOT := /assig/$(USER)/cl/runtime
#ANTLR_ROOT := /usr/local
ANTLR_ROOT := /usr
```

cal descomentar el `ANTLR_ROOT` segons on tinguem instal·lat l'antlr.