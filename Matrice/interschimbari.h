#ifndef INTERSCHIMBARI_H_INCLUDED
#define INTERSCHIMBARI_H_INCLUDED
#include <iostream>
#include <fstream>

using namespace std;

void interschimbareLinii(int a[100][100], int m, int l1, int l2)
{
    for (int j = 0; j < m; j++)
    {
        int aux = a[l1][j];
        a[l1][j] = a[l2][j];
        a[l2][j] = aux;

    }
}

void interschimbareColoane(int a[100][100], int n, int c1, int c2)
{
    for (int i = 0; i < n; i++)
    {
        int aux = a[i][c1];
        a[i][c1] = a[i][c2];
        a[i][c2] = aux;
    }
}

void afisareMatrice(int a[100][100], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << ' ';
        }

        cout << endl;
    }
}

//1:Scrie o funcție care interschimbă 
//prima linie cu ultima, a doua cu penultima, și tot așa. Linia din mijloc,dacă există, rămâne pe loc.

void liniiInOglinda(int a[100][100], int n, int m)
{
    
    for (int i = 0; i < n / 2; i++)
    {
        interschimbareLinii(a, m, i, n - 1 - i);
    }

    afisareMatrice(a, n, m);
}

void sol1()
{
    // Cazul 1
    int a[100][100] = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8}
    };
    int n1 = 4, m1 = 2;
    liniiInOglinda(a, n1, m1);
    cout << endl;

    // Cazul 2
    int b[100][100] = {
        {1, 2},
        {3, 4},
        {5, 6}
    };
    int n2 = 3, m2 = 2;
    liniiInOglinda(b, n2, m2);
}

//2: Scrie o funcție care interschimbă coloana cu suma maximă (prima, la egalitate) cu prima coloană.

void coloanaGreaPePrimulLoc(int a[100][100], int n, int m)
{
    int sMax = -1000000000, colMax = 0;
    for (int j = 0; j < m; j++)
    {
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            s += a[i][j];
        }
        if (j == 0 || s > sMax)
        {
            sMax = s;
            colMax = j;
        }
    }

    if (colMax != 0)
    {
        interschimbareColoane(a, n, 0, colMax);
    }
    afisareMatrice(a, n, m);
}

void sol2()
{
    // Caz 1
    int a[100][100] = {
        {1, 9, 2},
        {3, 8, 4},
        {5, 7, 6}
    };
    int n1 = 3, m1 = 3;
    coloanaGreaPePrimulLoc(a, n1, m1);
    cout << endl;


    // Caz 2 
    int b[100][100] = {
        {1, 2},
        {2, 1}
    };
    int n2 = 2, m2 = 2;

    coloanaGreaPePrimulLoc(b, n2, m2);
}

#endif