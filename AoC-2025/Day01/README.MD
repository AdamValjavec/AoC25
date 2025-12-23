V datoteki main.cpp vključimo potrebne datoteke in prebiramo vrstico po vrstico in jo shranjujemo v svoj razred, nato pa z metodami razreda preverjamo kolikokrat se ustavi na 0 oz. kolikokrat prečka čez 0 ter na koncu vrnemo rezultat.

V datoteki ura.h definiramo razred. v datoteki ura.cpp pa podamo definicijo metod, števec je v začetnem stanju na poziciji 50. 

Pri prvi stopnji preberemo v katero smer se zavrtimo. Glede na to v katero smer se zavrtimo, z if stavkom izberemo pravo smer vrtenja ure (prištevanje/odštevanje) in sedajšnji poziciji prištejemo/odštejemo pozicijo, in uporabimo modulo (ostanek pri celošt. deljenju) da ostanemo znotraj območja in jo zapišemo v našo novo pozicijo, za katero preverimo, če se nahaja na 0. Če se nahaja na 0, števcu prištejemo +1. Pri negativni smeri moramo še poskrbeti, da smo znotraj območja, zato prištejemo +100. 

Pri drugi stopnji prav tako izberemo smer vrtenja z if stavkom. Do naše razdalje pa se premikamo s for zanko. En korak na enkrat in preverjamo če smo na 0, in če smo prištevamo k števcu. Vsakič preden zapišemo našo novo pozicijo uporabimo modulo, da ostanemo znotraj našega območja.  