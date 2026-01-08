V datoteki main.cpp kličemo metode, v datoteki sestavine.h definiramo razred, v datoteki sestavine.cpp pa podamo definicijo metod.

Najprej preberemo datoteko. Na začetku inputa so najprej intervali, ki jih shranimo v 2D vector [[zač,kon],[zač,kon]...], ID pa v vector ids. V prvi stopnji se s for zanko pomikamo po vectorju ids, za vsak ID preverimo (z drugo for zanko se pomikamo po intervalih), če se ta ID nahaja znotraj intervala (ali je hkrati večji pd začetka intervala in hkrati manjši od konca intervala) če je povečamo števec, če najdemo en interval ki ustreza, gremo na naslednjo ID.

V drugi stopnji intervale posortiramo po velikosti. Potem pa seštevamo in združujemo te intervale. Začnemo pri prvem intervalu in se s for zanko premikamo po intervalih in z if zanko preverjamo prikrivanje in po potrebi prištejemo v total. 






