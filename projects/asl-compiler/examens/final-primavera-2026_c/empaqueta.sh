#! /bin/bash

# Aquest script crea el fitxer examen-nom.cognom.tgz que cal pujar al raco

# us:  ./empaqueta.sh

#  Aquest script ha d'estar situat en el directori arrel de 
#  la practica, que ha de contenir els subdirectoris
#  'asl', 'common', i 'jps'
#

BASEDIR=$(dirname $0)

cd $BASEDIR

echo "Nom: $USER" | tee noms.txt

echo "Si has fet la practica en parella, indica el nom del teu company.  Si l'has feta individualment, simplement prem <enter>."
read PARTNER
PARTNER=`echo $PARTNER | sed 's/ /./g' | tr '[:upper:]' '[:lower:]'`

if (test "x$PARTNER" != "x"); then echo "Parella: $PARTNER" >> noms.txt; fi


tar -czvf examen-$USER.tgz asl/Asl.g4 asl/SymbolsVisitor.[ch]* asl/TypeCheckVisitor.[ch]* asl/CodeGenVisitor.[ch]* noms.txt
