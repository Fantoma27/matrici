#ifndef PARCURGERE_H_INCLUDED
#define PARCURGERE_H_INCLUDED
#include <iostream>
#include <fstream>
using namespace std;

//Scrie o funcție care afi șează, pe un rând, sumele elementelor afl ate: deasupra diagonalei principale
//subdiagonala principală, 
//deasupra diagonalei secundare, sub diagonala secundară, în ordinea asta.
void sumeDiagonale(int a[100][100], int n)
{
    int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) {
                s1 += a[i][j];
            }
            if (i >= j) {
                s2 += a[i][j];
            }
            if (i + j <= n - 1) {
                s3 += a[i][j];
            }
            if (i + j >= n - 1) {
                s4 += a[i][j];
            }
        }
    }
    cout << s1 << " " << s2 << " " << s3 << " " << s4 << endl;
}

void sol1() {
    int a[100][100] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    sumeDiagonale(a, 3);
}

//Scrie o funcție care afișează care diagonală are suma mai mare: principala, secundara, sau egale.

void sDiagPrincipala(int a[100][100], int n, int &s)
{
    s = 0;
    for(int i = 0; i < n; i++)
    {
        s += a[i][i];
    }
}

void sDiagSecundara(int a[100][100], int n, int &s)
{
    s = 0;
    for(int i = 0; i < n; i++)
    {
        s += a[i][n - i - 1];
    }
}

int sol2()
{
    int a[100][100] = {
        {1, 2, 5},
        {4, 5, 6},
        {7, 8, 9}
    };
    int n = 3;
    int s1, s2;
    sDiagPrincipala(a, n, s1);
    sDiagSecundara(a, n, s2);
    if(s1 > s2)
    {
        cout << "Principala";
    }
    else if(s2 > s1)
    {
        cout << "Secundara";
    }
    else
    {
        cout << "Egale";
    }
}

//Scrie o funcție care întoarce câte elemente de pe diagonala principală sunt strict 
//mai mari decât media aritmetică (ca număr real) a elementelor de deasupra ei. 
//Dacă deasupra diagonalei nu e niciun element,afișează NU EXISTA.

void sumaDeasupraPrincipala(int a[100][100], int n, int &ma)
{
    int s = 0;
    int ct = ;
    for(int i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            s += a[i][j];
            ct++;
        }
    }
    

}


#endif