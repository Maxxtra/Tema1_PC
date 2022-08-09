#include <stdio.h>
#include <string.h> //biblioteca pentru sirurile de caractere

/**
Facem functia pentru filtrul smooth ce are ca parametrii matricea initiala,
matricea auxiliara si dimensiunile acestora; functia este void deoarece
matricea este un pointer.
Parcurgem matricea auxiliara pe linii si coloane pentru a aplica filtrul.
Evitam elementele de pe marginea matricei(sus, jos, stanga, dreapta).
Elementele matricei b le editam folosindu-ne de valorile initiale ale
matricei; aplicam formula din enunt pentru a face editarile**/
void smooth(double a[][100], double b[][100], int N, int M)
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            if (i != 0 && j != 0 && i != (N - 1) && j != (M - 1))
                b[i][j] = (a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][j + 1] +
                           a[i][j - 1] + a[i][j] + a[i][j + 1] +
                           a[i + 1][j - 1] + a[i + 1][j] + a[i + 1][j + 1]) /
                          9;
}

/**
Facem functia pentru filtrul blur ce are ca parametrii matricea initiala,
matricea auxiliara si dimensiunile acestora; functia este void deoarece
matricea este un pointer. 
Parcurgem matricea auxiliara pe linii si coloane pentru a aplica filtrul.
Evitam elementele de pe marginea matricei(sus, jos, stanga, dreapta).
Elementele matricei b le editam folosindu-ne de valorile initiale ale
matricei; aplicam formula din enunt pentru a face editarile**/
void blur(double a[][100], double b[][100], int N, int M)
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            if (i != 0 && j != 0 && i != (N - 1) && j != (M - 1))
                b[i][j] = (a[i - 1][j - 1] + 2 * a[i - 1][j] + a[i - 1][j + 1] +
                           2 * a[i][j - 1] + 4 * a[i][j] + 2 * a[i][j + 1] +
                           a[i + 1][j - 1] + 2 * a[i + 1][j] + a[i + 1][j + 1]) /
                          16;
}

/**
Facem functia pentru crearea unei matrice auxiliare ce are aceleasi dimensiuni
si elemente ca matricea initiala; functia are ca parametrii matricea ce va fi
copiata, noua matrice si dimensiunile acestora; functia este void deoarece
matricea este un pointer.
Parcurgem matricea care se va copia pe linii si coloane. Copiem elemenetele.
**/
void auxiliar(double matrice1[][100], double matrice2[][100], int N, int M)
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            matrice2[i][j] = matrice1[i][j];
}

/**
Facem functie pentru citirea matricei; functia are ca parametrii matricea si
dimensiunile acesteia; functia este void deoarece matricea este un pointer.
Parcurgem matricea pe linii si coloane. Citim elementele matricei.**/
void citire(double a[][100], int N, int M)
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            scanf("%le", &a[i][j]);
}

/**
Facem functie pentru afisara matricei; functia are ca parametrii matricea si
dimensiunile acesteia; functia este void deoarece matricea este un pointer.
Parcurgem matricea pe linii si coloane. Afisam elementele.
Cand ajungem la final de linie, trecem pe urmatoarea.*/
void afisare(double a[][100], int N, int M)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
            printf("%8.3lf", a[i][j]);
        printf("\n");
    }
}
int main()
{
    /**
Am declarat in ordine:
* tipul datelor din enunt
* initializam cele doua matrice cu tipul double, deoarece calculele sunt mai
exacte; matricea a[][] este cea initiala, iar b[][] este cea auxiliara
* luam un sir de caractere in care vom retine tipul filtrului care se va
aplica; are dimensiune maxima 7, deoarece cuvantul smooth, fiind mai lung decat
blur, are 6 caractere;
* parametrul pe care il vom utiliza;**/
    int N, M, p;
    double a[100][100], b[100][100];
    char filtru[7];
    int i;
    scanf("%d %d", &N, &M);
    //citim cele doua dimensiuni ale matricei; N-linii, M-coloane
    if (0 < N && N < 100 && 0 < M && M < 100) //verificam restrictiile problemei
    {
        // Citim matricea. Citim numarul de filtre care se vor aplica.
        citire(a, N, M);
        scanf("%d", &p);
        for (i = 0; i < p; i++)
        {
            /**
Citim filtrul curent. Cream o matrice auxiliara b; copiem elementele din a in b
Daca filtrul este smooth atunci se va executa; -explicatie: comparam cele doua
siruri-cel citit si smooth; daca ele sunt identice, atunci se va executa
filtrul. Aplicam filtrul smooth pe foaie. 
Daca nu, aplicam filtrul blur pe foaie.
La final, copiem elementele din b in a.**/
            scanf("%s", filtru);
            auxiliar(a, b, N, M);
            if (!strcmp(filtru, "smooth"))
                smooth(a, b, N, M);
            else
                blur(a, b, N, M);
            auxiliar(b, a, N, M);
        }
        afisare(b, N, M); // afisam matricea finala
    }
    return 0;
}
