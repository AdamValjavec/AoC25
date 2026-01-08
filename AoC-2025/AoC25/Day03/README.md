V datoteki main.cpp vključimo potrebne datoteke in prebiramo vrstice iz inputa. Nato z metodo za prvo stopnjo izračunamo vsoto največjih napetosti, enako za 2 stopnjo.

V datoteki baterije3.h definiramo razred, v datoteki baterije3.cpp pa podamo definicijo metod.

Vrstico shranimo v string. Pri prvi stopnji uporabimo brute force metodo, kjer preverimo vse variacije z dvema for zankama in if stavkom. Pri drugi stopnji, določimo število vseh števil v vrstici, nato znotraj for zanke izračunamo katere številke lahko vzamemo, da bomo še vedno ustrezali pogojem (n-(12-picked)) in izberemo največje število. Prejšnje največje število nato pomnožimo z 10 in mu prištejemo zdajšnje število.

Sproti seštevamo vsote in jih na koncu prikažemo.


