1. Quin dels següents errors s'ha d'utilitzar quan detectem que un identificador no es una funció: `isNotCallable`, `isNotProcedure`, `isNotFunction`?

    - `isNotCallable`: quan l'id no es ni una funció i ni una acció/procediment, i necessitem que sigui una de les dues. Aquest error es reporta abans que els dos propers.
    - `isNotProcedure`: quan l'id no es una acció/procediment i necessitem que ho sigui. I.e. retorna un valor, es una funció. No l'utilitzem, ja que nosaltres permetem la crida de funcions com si fossin accions.
    - `isNotFunction`: quan l'id no es una funció i necessitem que ho sigui. I.e. no retorna un valor, es una acció.

