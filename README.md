# Tema1_PC

Problema 1 - Operatii cu intervale
Mai intai am scos pe foaie ideile matematice, incercand sa descopar toate
cazuril matematice posbile. Dupa aceea am gandit problema in felul urmator:
*pentru interogarea 1: 
-intersectia poate sa fie vida sau sa fie una normala; 
cea normala se face prin a afla maximul capetelor din stanga si minimul 
celor din  dreapta;
- reuniunea poate sa fie intre multimea vida si un interval sau intre doua 
interale( aici includem si cazul dintre un interval si un numar);
daca este primul caz, am considerat ca rezult intervalul diferit de multimea
vida; in al doilea am considerat ca rezultat minimul( pentru ca intervalul de 
reuniune trebuie sa fie mami mare decat cel de intersectie) si maximul capetelor
de interval.
*pentru interogare 2:
- am pus tipurile de interogari intr-un vector;
-am verificat ce tip sunt si am apelat functiile facute mai sus(este analog);
-la final doar, rezultatul obtinut anterior devine de fapt primul interval si
citim al doilea interval;
-afisarea are 3 cazuri: 
i)cea clasica; doua capete de interval sunt diferite;
ii) daca rezultatul este multimea vida;
iii) daca avem doar un element;

Problema 2 - Joc
- mai intai am transformat in baza 2 i returile le-am pus in sirul de caractere
(daca era numarul divizibil cu 2 puneam caracterul 0, altfel 1)
-numarul dat, l am transpus intr o matrice de 4x4( caci tot numarul avea 16 biti)
-am parcurs trnasformarile date din enunt si concomintent am efectuat si 
transformarile din acea matrice; am luat 2 cazuri si nu 3 ca in enunt, deoarece
la al 3-lea( cand si poz initiala si cea finala sunt 0) nu se modifica matricea
initiala cu nimic;
- am actualizat vectorul de caractere in urma parcurgerii matricei finale;
- am transformat vectorul de caractere intr-un numar in baza 10; am folosit
metoda clasica de a transforma un numar din baza 2 in baza 10.

Problema 3 - Filtre
-am parcurs numarul de filtre;
-am creat o matrice auxiliara prin copiere element cu element;
-am verificat ce tip de filtru este:
i) daca este smooth am modificat elementele din matricea auxiliara conform 
formulei din enunt;
ii) analog pentru blur;
-matricea auxliara devine de fapt matricea initiala, procedul repetandu-se

Problema 4 - Soldati
-am pus intr-un vector numarul de soldati din fiecare linie;
- am aflat pozitia minima de soldati din toate cele k linii;
-am afisat;
-am pus pe pozitia aceea valoarea maxima(M)+1, deoarece nu se va atinge 
niciodata in acest fel;
- precedeul a continuat, punand pe urmatoarea pozitie minima vlaorea maxima+1;
