V datoteki main.cpp kličemo metode, v datoteki stroj.h definiramo razred, v datoteki stroj.cpp pa podamo definicijo metod.

Logika reševanja je bila brute force. Vsak gumb ima dve možnosti, ali je pritisnjen ali pa ne, če ga šeenkrat dodatno pritisneš, nima smisla, ker je isto, kot da ga nebi pritisnil. Zato obstaja 2^m možnih kombinacij. v kodi smo šli čez vse te možne kombinacije in preverjali, če se na koncu določena kombinacija ujema z želenim diagramom lučk. Hkrati smo primerjali minimalno število pritiskov znotraj kombinacij za en stroj. To število minimalnih pritiskov smo potem sešteli. 







