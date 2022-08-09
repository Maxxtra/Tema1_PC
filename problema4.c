#include <stdio.h>

/**
Facem functie pentru citirea matricei; functia are ca parametrii matricea si
dimensiunile acesteia; functia este void deoarece matricea este un pointer.
Parcurgem matricea pe linii. Parcurgem matricea pe coloane**/
void citire(int a[][100], int N, int M)
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            scanf("%d", &a[i][j]);
}

/** 
Facem functie pentru aflarea numarului de soldati de pe o linie; functia are ca
paramerii matricea, numarul de coloane si linia curenta. Parcurgem elementele
de la stanga la dreapta. Daca gasim un soldat, numarul de soldati va creste
*/
int nrsoldati(int a[][100], int M, int i)
{
    int nr = 0; //nr initial de soldati
    int j;
    for (j = 0; j < M; j++)
        if (a[i][j] == 1)
            nr++;
    return nr;
}

/**
Facem functie pentru a afla care dintre linii are numarul cel mai mic de
soldati. Parcurgem toate elementele vectorului, care sunt in numar de cate
linii are matricea. Aplicam algoritmul pentru a determina minimul. Retinem
pozitia unde se afla minimul.
Returnam pozitia.**/
int pozminim(int v[], int N, int minim)
{
    int poz;
    int i;
    for (i = 0; i < N; i++)
        if (v[i] < minim)
        {
            minim = v[i];
            poz = i;
        }
    return poz;
}
int main()
{
    int N, M, k; //datele din enunt
    int a[100][100], v[100], poz;
    int i;
    scanf("%d %d", &N, &M);
    if (0 < N && 0 < M && N < 100 && M < 100) //verificam restrictiile
    {
        //Apelam functia de citire a matricei. Verificam restrictiile
        citire(a, N, M);
        scanf("%d", &k);
        if (k <= N)
        {
            /**
Parcurgem linie cu linie. 
Facem un vector care sa retina cati soldati sunt pe fiecare linie.
**/
            for (i = 0; i < N; i++)
                v[i] = nrsoldati(a, M, i);
            for (i = 0; i < k; i++)
            {
                /** 
Vom afisa doar k linii slabe. Determinam pozitia unde se afla cei mai
putini soldati. Ii atribuim valoarea maxima+1 pe care aceasta o poate o avea.
Afisam pana la penultimul, inclusiv, element cu spatiu. 
Afisam ultimul element fara spatiu dupa acesta si dupa trecem pe o linie noua.
**/
                poz = pozminim(v, N, M + 1);
                v[poz] = M + 1;
                if (i < k - 1)
                    printf("%d ", poz);
                else
                    printf("%d\n", poz);
            }
        }
    }
    return 0;
}
