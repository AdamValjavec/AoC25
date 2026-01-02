V datoteki main.cpp vključimo potrebne datoteke in preberemo vrstico iz inputa. Nato z metodami za prvo stopnjo izračunamo vsoto neveljavnih ID in jo prikažemo, postopek ponovimo še za 2. stopnjo.

V datoteki baterije.h definiramo razred, v datoteki baterije.cpp pa podamo definicijo metod.

Metode imamo ločene za prvo in drugo stopnjo, le vsota neveljavnih ID-jev je univerzalna. Pri prvi stopnji je logika taka, da interval razdelimo na dva dela (manjše in večje število, ki predstavljata začetek in konec intervala) in preverjamo vsa števila znotraj intervala. Število preverimo tako, da ga razdelimo na polovici in jih primerjamo med sabo. Če sta enaki to ustreza kriteriju, za to ga dodamo v vektor neveljavnih ID-jev.

Pri drugi stopnji prav tako interval razdelimo na dva dela... in preverjamo vsa števila znotraj intervala. Število pa tu preverimo rahlo drugače kot v 1. stopnji. Preverimo dolžino niza, nato z dvema for zankama ustvarjamo vzorec ponovitev od dolžine ponavljanja (1) do dolžine ponavljanja (dolžina niza/2). Z if stavkom preverjamo, če naš nastali vzorec ustreza pogojem, če jim, ga zapišemo v vektor neveljavnih ID-jev.

