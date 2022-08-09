#include <stdio.h>
#include <stdlib.h> //biblioteca pentru functia abs()

/** Functia clasica pentru a afla maximul a doua numere
un calcul matematic simplu poate demonstra formula; 
abs este functia pentru a determina valoarea absoluta a rezultatului**/
int maxim(int x, int y)
{
    return ((x + y + abs(x - y)) / 2);
}

// Analig ca la maxim.
int minim(int x, int y)
{
    return ((x + y - abs(x - y)) / 2);
}

/** Facem o functie pentru a determina intersectia a doua intervale; 
Este de tipul void, deoarece rezultatul este determinat de cei doi pointer-i.
Verificam inca de la inceput daca primul interval are macar un element in 
comun cu al doilea. Daca nu este, rezultatul intersectiei celor doua o sa 
fie multimea vida. Punem veridicitatile matematice pentru care un 
interval exista. Intersectia intervalelor [x1,x2] si [x3,x4] este data de
 cea mai mare voalare din [x1,x2] ce se regaseste prima data in [x3,x4]. Cea 
 mai mica valoare din [x3,x4] care este cea mai mare din [x1,x2]**/
void intersectie(int x1, int x2, int x3, int x4, int *x5, int *x6)
{
    if (x1 > x4 || x2 < x3)
    {
        (*x5) = 0;
        (*x6) = 0;
    }
    else if (x1 <= x2 && x3 <= x4)
    {
        (*x5) = maxim(x1, x3);
        (*x6) = minim(x2, x4);
    }
}

/** Facem o functie pentru a determina reuniunea a doua intervale;
Este de tipul void, deoarece rezultatul este determinat de cei doi pointer-i.
Punem veridicitatile matematice pentru care un interval exista. Reuniunea este 
procesul invers reuniunii.**/
void reuniune(int x1, int x2, int x3, int x4, int *x5, int *x6)
{
    if (x1 <= x2 && x3 <= x4)
    {
        (*x5) = minim(x1, x3);
        (*x6) = maxim(x2, x4);
    }
}

/** Facem o functie pentru afisare. 
Daca in urma celor doua operatii avem capete diferite de interval, le vom afisa
in ordine. Daca in urma celor doua operatii avem intervalul [0,0], ce 
reprezinta multimea vida, vom afisa 0. Dca in urma celor doua operatii avem 
capete indetice de interval diferite de 0, atunci vom afisa 
elementul respectiv**/
void afisare(int x5, int x6)
{
    if (x5 != x6)
        printf("%d %d\n", x5, x6);
    if (!x5 && !x6)
        printf("%d\n", x5);
    if (x5 == x6 && x5)
        printf("%d %d\n", x5, x6);
}

int main()
{

    int N, M; // tipul datelor din enunt
    int x1, x2, x3, x4, x5, x6;
    /*x<1-4> reprezinta capetele intervalelor de prelucrat;
x5,x6 reprezinta rezultatul in urma prelucrarii; 
ii facem pointeri pe 5 si 6, deoarece va trebui apelata valoarea lor*/
    int interogare, operatie, vector_operatii[100];
    int i, j;
    scanf("%d", &N); //citim numarul de interogari

    /* Parcurgem cu functia repetitiva cu for, caci avem un numar cunoscut de
pasi, numarul de interogari. Citim apoi interogarea aferenta contorului:**/
    for (i = 0; i < N; i++)
    {

        scanf("%d", &interogare);
        if (interogare == 1)
        {

            /** Daca interogarea este simpla:
* citim tipul operatiei date de interogarea 1 alaturi de cele 4 capete de 
interval
* verificam daca interogarea este intersectie, deci aplicam functia pentru a
afla intersectia celor doua intervale;
* verificam daca interogarea este reuniune extinsa; verificam daca intervalul
[x1,x2] este de fapt multimea vida; Cum [x1,x2]=[0,0] care este explicat
in cerinta ca fiind multimea vida, atunci un interval intersectat cu multimea
vida are ca rezultat intervalul in cauza; daca nu este, aplicam functia pentru
a afla intersectia celor doua intervale.
* apelam functia de afisare**/
            scanf("%d %d %d %d %d", &operatie, &x1, &x2, &x3, &x4);
            if (operatie == 1)
                intersectie(x1, x2, x3, x4, &x5, &x6);
            if (operatie == 2)
            {
                if (!x1 && !x2)
                {
                    x5 = x3;
                    x6 = x4;
                }
                else
                    reuniune(x1, x2, x3, x4, &x5, &x6);
            }
            afisare(x5, x6);
        }
        if (interogare == 2)
        {
            /**Daca interogarea este compusa:
 * citim numarul de operatii pentru interogarea compusa
 * parcurgem cu functia repetitiva for, deoarece avem un numar cunoscut de
pasi, numarul de operatii; 
*  cum operatiile sunt citite pe un singur rand, le vom retine pe toate
intr-un vector de tipul int;
* //am ales sa citesc primele doua intervale separat, deoarece rezolv problema
prin picaj( primele doua intre ele, apoi rezultatul cu al treilea 
interval etc)**/
            scanf("%d", &M);
            for (j = 0; j < M; j++)
            {
                scanf("%d", &operatie);
                vector_operatii[j] = operatie;
            }
            scanf("%d %d", &x1, &x2);
            scanf("%d %d", &x3, &x4);
            for (j = 0; j < M; j++)
            {
                /** Nu parcurgem de la 1, deoarece inca nicio operatie nu
s a efectuat intervalelor. Cele doua structuri decizionale se trateaza analog
ca mai sus**/
                if (vector_operatii[j] == 1)
                    intersectie(x1, x2, x3, x4, &x5, &x6);
                if (vector_operatii[j] == 2)
                {
                    if (!x1 && !x2)
                    {
                        x5 = x3;
                        x6 = x4;
                    }
                    else
                        reuniune(x1, x2, x3, x4, &x5, &x6);
                }
                /** Rezultatul prelucrarii ultimelor doua intervale devine
urmatorul prim interval de prelucrare**/
                x1 = x5;
                x2 = x6;
                /** Daca inca nu s-a ajuns la ultima operatie, citim in 
continuare. Citim al doilea interval aferent celui de mai sus*/
                if (j < (M - 1))
                    scanf("%d %d", &x3, &x4);
            }
            afisare(x5, x6); // apelam functia de afisare
        }
    }
    return 0;
}
