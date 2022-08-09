#include <stdio.h>
#include <string.h> //biblioteca pentru sirurile de caractere
#include <math.h>   //biblioteca pentru functia pow()

/** Facem functie pentru a transforma un numar din baza 10 in baza 2, iar
rezultatul sa fie pus intr-un sir de caractere; functia este void deoarece
vectorul este  un pointer. Pentru a scrie corect un numar in baza2,
resturile trebuie puse in ordine inversa aferenta obtinerii lor, fapt pentru
care parcurgem numarul de elemente al vectorului( 16 biti in cazul problemei
noastre) invers.
Verificam daca numarul este divizibil cu 0. Daca restul este 0, atunci pe
pozitia i trecem caracterul '0'.
Daca restul impartirii este 1, atunci pe pozitia i trecem caracterul '1'.
Pentru a scrie numarul in baza 2, trebuie sa efectuam impartiri repetate
la baza=2.**/
void dec_to_bin(int n, char s[])
{
    int i;
    for (i = 15; i >= 0; i--)
    {
        if (n % 2 == 0)
            s[i] = '0';
        else
            s[i] = '1';
        n = n / 2;
    }
}

/** Facem functie pentru a transforma valorile caracterelor intr-un numar in
baza 2 pe care il vom transforma intrun-un numar scris in baza 10; functia este
void deoarece vectorul este  un pointer. Initializam numarul pe care noi
vrem sa-l transformam din baza 2 in baza 10 cu 0, deoarece el o sa fie de fapt
o suma a puterilor lui 2. Alegem un parametru. Stiind cate elemente are
vectorul de caractere, uitilizam o functie repetitiva. 
Daca intalnim caracterul '1', atunci la suma se va adauga baza, adica 2, la
puterea numarului de cifre-1, 15 in cazul nostru, minus numarul pozitiei pe
care acesta se afla.
Returnam suma creata sub forma de un numar int.**/
int bin_to_dec(char s[])
{
    int x = 0;
    int i;
    for (i = 0; i < 16; i++)
        if (s[i] == '1')
            x += pow(2, (15 - i));
    return x;
}

int main()
{
    /** Am declarat in ordine:
* tipul datelor din enunt
* alegem o matrice pentru a reprezenta configuratia hartiei;
 o umplem cu zero-uri deoarece este elementul preponderent;
* li= linia initiala, ci= coloana initiala, lf= linia finala, cf= coloana
finala; pozitiile aferente unei mutari;
* parametrii pe care ii vom utiliza in functiile repetitive
*un vector de chaaractere in care retinem caracterele '0' si '1';
are dimensiunea 17 doarece suntem scriem pe 16 biti;
*/
    int n, m;
    int a[100][100];
    int li, ci, lf, cf;
    int i, j;
    char s[17] = {'0'};
    scanf("%d", &n);
    //citim numarul initial ce va determina configuratia initiala a hartiei
    if (0 <= n && n < pow(2, 16)) //verificam restrictiile
    {
        /**
Scriem numarul n din baza 10 in baza 2 pe 16 biti; momentan rezultatul
este retinut in vectorul de caractere. Initializam o constanta cu 0, pe post de
contor. Executa efectuarea hartiei initiale; o initializam cu numarul scris in
baza 2 pe 16 biti. Cei doi parametrii au doar 4 valori, deoarece o matrice
patratice cu 16 elemente are 4 linii si 4 coloane. **/
        dec_to_bin(n, s);
        int c = 0;
        for (i = 0; i < 4; i++)
            for (j = 0; j < 4; j++)
            {
                /** 
Am ales un parametru extern deoarece asa este mai eficient sa cautam
valorile de care avem nevoie. Daca intalnim characterul'1' pe pozitia c in
vectorul de caractere, il vom transpuene ca valoarea int 1 in matrice pe
pozitia gasita. Crestem controrul pentru a putea parcurge in continuare
vectorul.**/
                if (s[c] == '1')
                    a[i][j] = 1;
                c++;
            }
        scanf("%d", &m); //citim numarul de mutari
        for (i = 0; i < m; i++)
        {
            /**
Parcurgem cu functia repetitiva for, deoarece avem un numar cunoscut de
pasi, numarul de mutari. Citim de unde si unde se vor face mutarile.
Incepem sa verificam conditiile din enunt:
* daca cele doua valori citite sunt egale cu 1, atunci ele vor deveni 0;
* daca valoarea initiala este 0 si cea finala este 1, valorile lor se
interschimba;
* daca ambele sunt 0, nu se intampla nimic;**/
            scanf("%d %d %d %d", &li, &ci, &lf, &cf);

            if (a[li][ci] && a[lf][cf])
            {
                a[li][ci] = 0;
                a[lf][cf] = 0;
            }
            if (a[li][ci] && !a[lf][cf])
            {
                a[li][ci] = 0;
                a[lf][cf] = 1;
            }
        }
        c = 0;
        //reinitializam contorul pentru a putea concatena matricea intr-un vector
        for (i = 0; i < 4; i++)
            for (j = 0; j < 4; j++)
            {
                /**
Daca elementul curent are valoarea 1, atunci in vectorul de caractere va
primi pe pozitia c caracterul '1'.
Daca elementul curent are valoarea 0, atunci in vectorul de caractere va primi
pe pozitia c caracterul '0'.
Crestem contorul pentru a putea trece la alta pozitie in vector**/
                if (a[i][j])
                    s[c] = '1';
                else
                    s[c] = '0';
                c++;
            }
        printf("%d\n", bin_to_dec(s));
        // afisam valoarea in baza 10 a numarului dupa mutarile efectuate
    }
    return 0;
}
