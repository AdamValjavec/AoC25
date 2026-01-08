V datoteki main.cpp kličemo metode, v datoteki tuba.h definiramo razred, v datoteki tuba.cpp pa podamo definicijo metod.

Datoteko preberemo po vrsticah in jo shranimo v grid. V prvi vrstici poiščemo S. Uporabljamo aktivne matrike, ki preprečujejo podvajanje žarkov, inicializiramo žarek na S - ju in iterativno simuliramo po vrsicah zraven štejemo število delitev.

Za drugo stopnjo potrebujemo število različnih časovnih linij, prav tako se izognemo rekurziji, da se izognemo preveliki porabi spomina --> gremo od spodnje vrstice navzgor. Spodnji vrstici damo vsakemu elementu vrednost 1. Ko se premikamo po vrsticah navzgor pa upoštevamo, da . in S predstavljata vrednost pod njima, ^ pa predstavlja seštevek levega in desnega soseda (vrstice spodaj), tako pridemo do zgornje vrstice in odčitamo vse možne poti do S. 





