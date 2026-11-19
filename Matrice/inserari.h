#ifndef INSERARI_H_INCLUDED
#define INSERARI_H_INCLUDED
#include <iostream>
#include <fstream>

using namespace std;

void inserareLinie(int a[100][100], int& n, int m, int lin)
{
    for (int i = n - 1; i >= lin; i--)
    {
        for (int j = 0; j < m; j++)
        {
            a[i + 1][j] = a[i][j];
        }
    }
    n++;
}

void inserareColoana(int a[100][100], int n, int& m, int col)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = m - 1; j >= col; j--)
        {
            a[i][j + 1] = a[i][j];
        }
    }

    m++;
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

//1: Scrie o funcție care inserează între oricare două coloane vecine o coloană cu zerouri.

void zeroIntreColoane(int a[100][100], int n, int& m)
{
    for (int j = m - 1; j >= 1; j--)
    {
        inserareColoana(a, n, m, j);
        for (int i = 0; i < n; i++)
        {
            a[i][j] = 0;
        }
    }

    afisareMatrice(a, n, m);
}

void sol1()
{
    // Cazul 1
    int a[100][100] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    int n1 = 2, m1 = 3;

    zeroIntreColoane(a, n1, m1);
    cout << endl;


    // Cazul 2
    int b[100][100] = {
        {7},
        {8}
    };
    int n2 = 2, m2 = 1;
    zeroIntreColoane(b, n2, m2);
}

//Scrie o funcție care inserează, după linia cu suma maximă (prima, la egalitate), dublul ei.

void dubluLinieGrea(int a[100][100], int& n, int m)
{
    int sMax = -1000000000, linMax = 0;
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = 0; j < m; j++)
        {
            s += a[i][j];
        }
        if (i == 0 || s > sMax)
        {
            sMax = s;
            linMax = i;
        }
    }

    inserareLinie(a, n, m, linMax + 1);
    for (int j = 0; j < m; j++)
    {
        a[linMax + 1][j] = a[linMax][j] * 2;
    }

    afisareMatrice(a, n, m);
}

void sol2()
{
    // Cazul 1
    int a[100][100] = {
        {1, 2, 3},
        {9, 8, 7},
        {5, 7, 9}
    };
    int n1 = 3, m1 = 3;
    dubluLinieGrea(a, n1, m1);
    cout << endl;


    // Cazul 2

    int b[100][100] = {
        {2, 4},
        {3, 3}
    };
    int n2 = 2, m2 = 2;
    dubluLinieGrea(b, n2, m2);
    cout << endl;

    // Caz 3
    int c[100][100] = {
        {1, 3},
        {2, 9}
    };

    int n3 = 2, m3 = 2;
    dubluLinieGrea(c, n3, m3);
}

#endif
