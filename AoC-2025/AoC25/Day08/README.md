V datoteki main.cpp kličemo metode, v datoteki povezave.h definiramo razred, v datoteki povezave.cpp pa podamo definicijo metod.

Datoteko beremo vrstico po vrstico in jo shranjujemo kot točke. V prvem delu naloge moramo skupaj spojiti 1000 najkrajših povezav. Za vse kombinacije točk izračuna razdaljo med njima, in jih sortira po razdalji. Nato združuje prvi 1000 najkrajših povezav in zmnoži velikosti treh največjih krogov. Združuje jih na način, da pogleda root-e obeh točk in če še nista v istem cilku jih združi drugače ne. 

Pri drugi stopnji, združuje toliko časa, dokler ne nastane le en cikel (na začetku je vsaka točka svoj cikel, ki se jih potem združuje). Na koncu vrne zmnožek x koordinat zadnje povezave.




