V datoteki main.cpp kličemo metode, v datoteki list.h definiramo razred, v datoteki list.cpp pa podamo definicijo metod.

Input datoteko prebiramo vrstico po vrstico in jo shranjujemo. Zadnjo vrstico shranimo posebej kot string. S for zankami stringstreamom ustvarimo 2D vektor numbers, ki ga kasneje uporabimo za seštevanje, množenje. S for zanko se pomikamo po vrsticah, z še dodatno for zanko se pomikamo po stolpcih z notraj vrstice in z if stavkom preverjamo ali bomo množili ali seštevali. To se vse skupaj sešteva in vrne kot rezultat.

Pri obravnavi druge stopnje, pa moramo ugotoviti in poskrbeti tudi za pravi allignment. To počnemo s funkcijo inProblem, ki v vektor problemStarts shranjuje, kje se začenjajo številke. V nadaljevanju poiščemo, kje se končajo te številke in ugotovimo začetni rezultat, glede na to ali bomo množili ali seštevali. Problem nato začnemo obdelovati od desne proti levi, in števila sestavljamo iz zgoraj navzdol z uporabo for zanke. String pretvorimo v število in jih glede na pogoj seštejemo/množimo, na koncu rezultat prištevamo skupaj k totalni vsoti.



