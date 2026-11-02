# Pràctica de Llenguatges de Programació: mini Forth - (Q1 2025‑2026)

Aquesta pàgina conté el desenvolupament d'un interpret d’un subconjunt de Forth implementat amb **ANTLR4** i **Python**.


## Estructura del projecte


- `forth.g4`: gramàtica ANTLR del llenguatge mini Forth.

- `forth.py`: script principal, que implementa la funció `interpret`.
​
- `eval.py`: implementació del visitor (`EvalVisitor`) que interpreta l’AST generat per ANTLR.
​
- `test.txt`: joc de proves en format doctest que comprova operadors, funcions, condicionals, recursivitat, comentaris i errors sintàctics.

- `Makefile`: definició de les comandes per generar els fitxers necessaris per l'execució del projecte.


## Instruccions per a l'execució

Executant la comanda `make` es generen tots els fitxers necessaris per executar el projecte, i automàticament s'executa el projecte amb el fitxer de joc de proves `test.txt`.

Si l'execució es vol fer de foma manual, cal seguir els següents passos:


1. `make antlr`: es generen tots el fitxers necessaris per a l'execució.

2. Per realitzar l'execució podem seguir dos camins:

    - `make test`: executa el projecte amb el fitxer de joc de proves `test.txt`. Alternativament, es pot fer servir la comanda `python3 -m doctest test.txt`.

    - `make execute`: executa l'interpret de python amb el fitxer `forth.py`, per fer proves interactives. Alternativament, es pot fer servir la comanda `python3 -i forth.py`.

3. Si es vol netejar el directori, es pot fer us de la comanda `make clean`.


## Disseny de la gramàtica

La gramàtica està dissenyada per reflectir fidelment la sintaxi del mini Forth descrita a l’enunciat, i per imposar algunes restriccions importants:

- Regla d'arrel:
    ```
    root : instr+ EOF
         ;
    ```
    Un programa es una seqüència d'instruccions fins a un `EOF`.

- Instruccions:
    ```
    instr : funcdef | atom
          ;
    ```
    Les instruccions del mini Forth son àtoms simples (nombres o identificadors d'operadors), o bé, definicions de funcions.

- Definició de funcions:
    ```
    funcdef : ':' ID bloc ';'
            ;
    ```
    Les funcions es composen d'un identificador (el token `ID`) i el seu cos (un bloc d'instruccions vàlides dins de la definició d'una funció), tots dos elements encapsulats entre els caràcters `:` i `;`.

- Definició d'àtoms:
    ```
    atom : NUM                                             # nombre
         | (OP | ID)                                       # operador
         ;
    ```
    Un element atòmic o bé es un nombre enter (token `NUM`) o bé un operador, que pot ser natiu del llenguatge (token `OP`) o un identificador d'una funció definida prèviament (token `ID`). 

- Blocs de funcions i de sentències condicionals:
    ```
    bloc : (atom | recurse | condicional)+                                      
         ;
    ```
    Dins d'una funció, un bloc pot contenir:
    - Àtoms: nombres i/o operadors.
    - Condicionals.
    - La paraula reservada `recurse`, per fer recursivitat.

- Definició de `recurse`:
    ```
    recurse : 'recurse'
            ;
    ```
    La paraula reservada `recurse` s'ha hagut de definir com una regla independent per poder tenir un visitor dedicat. De forma alternativa, es podria haver posat la paraula de forma literal a la regla `bloc` i etiquetarla, però llavors ens veiem obligats a etiquetar `atom` i `condicional` dins de `bloc`. I aquestes dues últimes etiquetes serien redundants (ja que no son necessaries) i generarien confusions. Per tant, per simplicitat i per millorar la llegibilitat, s'ha optat per definir una regla específica per `recurse`.

- Condicionals:
    ```
    condicional : cond+=atom+ 'if' bloc_if=bloc 
                  ('else' bloc_else=bloc)? 'endif'
                ;
    ```
    En un condicional, la condició es una seqüència d'àtoms (nombres i operadors) i el cos del `if` i `else` son blocs. Com que els condicionals només es poden definir dins de funcions, es vàlid permetre que el cos del `if` i `else` tinguin condicionals anidats, així com la paraula reservada `recurse`. Per això s'ha decidit que els respectius cossos siguin blocs i no només seqüències d'àtoms.


- Token `OP`: inclou tots els operadors natius de mini Forth.

- Token `NUM`: representa els nombres enters.

- Token `ID`: representa identificadors de funcions. S'ha decidit que un identificador només pot començar amb el caràcter `_` o amb caràcters de l'alfabet anglès (en majúscula o minúscula), i la resta de caràcters només poden ser caràcters de l'alfabet anglès (en majúscula o minúscula) o nombres.

- Token `COMMENT`: reconeix tots els comentaris (expressats entre parèntesis) i els descarta. Si un dels parèntesis s'omet obtenim errors de sintàxi, i si ometem els dos només obtenim errors de sintàxi si alguna paraula del comentari no es pot interpretar com un identificador de funció. Les paraules que s'interpreten com a identificadors, si no son identificadors vàlids (es a dir, no s'ha definit cap funció amb aquells identificadors), simplement no succeeix res a nivell semàntic (s'ignoren). 

- Token `WS`: ignora espais, tabuladors i salts de línia.


## Disseny del visitor

### Estat intern

- `self.pila`

    Pila d’enters on es fan totes les operacions.
​

- `self.aplica_op`

    Diccionari que mapeja cada operador (`.s`, `+`, `swap`, etc.) a una acció Python (lambdes o mètodes privats).
​

- `self.funcions`
    
    Diccionari de definicions de funció. La clau es el nom de la funció i el valor el bloc de la funció.
​

- `self.funcions_act`

    Pila de noms de funció en execució, utilitzada per implementar `recurse` (per saber quina funció s’ha de tornar a cridar).


### Visitadors implementats


- `visitRoot`

    Itera sobre totes les instruccions del programa i les executa. Tot el bucle està dins d’un try/except que captura:

    - `IndexError`: intent d'acces a una posició inexistent de la pila o intent d'accés a una pila buida (quan es fa pop o accés per índex). Com a conseqüència es mostra `Error: pila buida!`.

    - `ZeroDivisionError`: intent de divisió per zero. Com a conseqüència es mostra `Error: intent de divisio per zero!`.
​

- `visitFuncdef`

    Desa el cos (`bloc`) de la funció al diccionari `self.funcions` sota el seu nom (`ID`). No executa el cos en aquest moment.
​

- `visitNombre`

    Llegeix el nombre (`NUM`) i l’afegeix a la pila.
​

- `visitOperador`

    Distingeix tres casos:

    - Si l’identificador de l'operador (un `ID`) apareix a `self.funcions`, es tracta d’una crida de funció. En aquest cas, es marca la funció identificada per `ID` com a funció activa, s'executa el seu bloc corresponent i, al finalitzar, es marca com a desactivada (es fa `pop` de `self.funcions_act`)
​
    - Si està a `self.aplica_op`, s’aplica l’operació corresponent (aritmètica, pila, relacional, etc).

    - Si no està en cap de les dues estructures anteriors, es tracta d'un identificador sintàcticament correcte, pero que semànticament no té significat. Per tant, s'ignora. 
​

- `visitRecurse`

    Obté el nom de la funció activada més recent i en visita de nou el seu cos.
​

- `visitCondicional`

    - Avalua tots els àtoms de la condició, col·locant el resultat al cim de la pila.

    - Fa pop del valor condicional:

        - Si és `-1` (cert), visita el bloc del `if`.

        - Si és diferent i existeix un bloc `else`, s'executa tal bloc.


### Mètodes privats

Les accions de `self.aplica_op` combinen lambdes per a operacions trivials i mètodes privats per operacions on l’ordre és crític o la semàntica és menys òbvia. No hi ha res rellevant a explicar dels mètodes privats, ja que el seu codi es molt auto significatiu.


## Disseny dels jocs de proves

Els jocs de proves a `test.txt` comproven:

- Operacions bàsiques de pila (`.s`, `.`) i comportament amb pila buida.

- Operadors aritmètics (`+`, `-`, `*`, `/`, `mod`).

- Operadors de manipulació de pila (`swap`, `2swap`, `dup`, `2dup`, `over`, `2over`, `rot`, `drop`, `2drop`).

- Operadors relacionals (`=`, `<>`, `<`, `<=`, `>`, `>=`) i booleans (`and`, `or`, `not`).

- Definició i ús de funcions, incloent composició de funcions i recursivitat.

- Condicionals amb i sense else.

- Comentaris entre parèntesis, que s’han de saltar.

- Errors de pila buida i divisió per zero.

- Errors sintàctics: condicionals fora de funció, definicions inacabades, endif sense if, comentari sense tancar.
