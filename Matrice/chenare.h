#ifndef CHENARE_H_INCLUDED
#define CHENARE_H_INCLUDED
#include <iostream>
#include <fstream>
using namespace std;

//Se citesc n și m. Scrie o funcție care afi șează câte elemente are fi ecare chenar al unei matrici 
//cu n linii șim coloane, de la gradul 0, câte unul pe linie. Matricea nu se citește.
int nrChenare(int n, int m)
{
    int mic = n;
    if (m < mic)
    {
        mic = m;
    }
    return (mic + 1) / 2;
}

int nrElementeChenar(int n, int m, int k)
{
    int l = n - 2 * k;
    int c = m - 2 * k;

    if (l <= 0 || c <= 0)
    {
        return 0;
    }
    if (l == 1)
    {
        return c;
    }
    if (c == 1)
    {
        return l;
    }
    return 2 * l + 2 * c - 4;
}

void elementeChenare(int n, int m)
{
    int total = nrChenare(n, m);
    for (int k = 0; k < total; k++)
    {
        cout << k << ' ' << nrElementeChenar(n, m, k) << endl;
    }
}

void sol1()
{
    elementeChenare(5, 3);
    cout << endl;

    elementeChenare(4, 4);
    cout << endl;
    elementeChenare(1, 4);
}

//Se citește k. Scrie o funcție care afi șează suma elementelor 
//chenarului de grad k, sau NU EXISTA dacămatricea nu are un 
//astfel de chenar.

int sumaChenar(int a[100][100], int n, int m, int k)
{
    int i1 = k, j1 = k, i2 = n - 1 - k, j2 = m - 1 - k;
    int s = 0;

    for (int j = j1; j <= j2; j++)
    {
        s += a[i1][j];
    }
    for (int i = i1 + 1; i <= i2; i++)
    {
        s += a[i][j2];
    }
    if (i2 > i1)
    {
        for (int j = j2 - 1; j >= j1; j--)
        {
            s += a[i2][j];
        }
    }
    if (j2 > j1)
    {
        for (int i = i2 - 1; i > i1; i--)
        {
            s += a[i][j1];
        }
    }

    return s;
}

void sumaChenarGradK(int a[100][100], int n, int m, int k)
{
    if (k < 0 || k >= nrChenare(n, m))
    {
        cout << "Nu exista" << endl;
    }
    else
    {
        cout << sumaChenar(a, n, m, k) << endl;
    }
}

void sol2()
{
    int a[100][100] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    sumaChenarGradK(a, 3, 3, 0);
    sumaChenarGradK(a, 3, 3, 1);
    sumaChenarGradK(a, 3, 3, 2);

    cout << endl;

    int b[100][100] ={
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12},
        {13, 14, 15}
    };

    sumaChenarGradK(b, 5, 3, 0);
    sumaChenarGradK(b, 5, 3, 1);
}


#endif