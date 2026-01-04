V datoteki main.cpp kličemo metode, v datoteki povezave.h definiramo razred, v datoteki plosce.cpp pa podamo definicijo metod.

Datoteko beremo vrstico po vrstico in jo shranjujemo kot točke. V prvem delu se z dvema for zankama pomikamo po točkah, s tem dosežemo, da gremo samo enkrat skozi vse točke. Izračunamo razdaljo med koordinato x in y, izračunamo absolutno vredost produkta dx in dy in ga primerjamo z dosedaj največjo vrednostjo.

V drugem delu moramo zaradi velikosti koordinat skompremisarti koordinate. To storimo tako, da odstranimo podvojene koordinate, jih uredimo in poindeksiramo, s zasedemo precej manj prostora v spominu. Zgradimo mrežo (prazno), in narišemo robove s for zanko in if stavki. Robovi so oznaceni kot zeleno točke označimo na rdeče. Nato moramo zapolniti notranjost tega poligona. Logika tu je, da od roba mreže, obiskujemo vse njene sosednje točke dokler ne pridemo do RDEČE ali ZELENE. Na začetku so bile vse točke ne obiskane (razen rdeče in zelene) po polnitvi so neobiskane točke ostale le še te znotraj poligona. Te neobiskane točke označimo z zeleno. Potem računamo podobno kot v prvem delu max površino, vendar z if stavkom preverjamo, če so vse celice znotraj našega pravokotnika zelene oz rdeče na kotih. 






