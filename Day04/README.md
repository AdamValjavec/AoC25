V datoteki main.cpp kličemo metoe, v datoteki papir.h definiramo razred, v datoteki papir.cpp pa podamo definicijo metod.

Datoteko prebiramo vrstico po vrstico in jo zapisujemo v 2D vektor, tako si ustvarimo grid. S funkcijo jeDostopna() glede na vhodne koordinate grida s for zanko preverimo sosede in štejemo, če je na manj kot na 4 mestih @. Funkcija prestejDostopne() se s for zanko premakne po celotnem gridu in šteje, koliko rol papirja je dostopnih.

Pri drugi stopnji logiko zapakiramo znotraj while loop. Najprej pregledamo celoten grid (s for zankami) in s funckijo jeDostopna. Če je na neki poziciji grida @ in je dostopna, koordinate tega zapišemo v nov vektor lokacij. Če je ta vektor lokacij prazen, se while zanka zaključi in dobimo število odstranjenih rol papirja. Iz vektorja lokacij ven preberemo koordinate @, ki jih zamenjamo s . . Glede na velikost vektorja lokacij prištevamo števcu, koliko rol papirja smo odvzeli.



