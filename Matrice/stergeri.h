#ifndef STERGERI_H_INCLUDED
#define STERGERI_H_INCLUDED
#include <iostream>
#include <fstream>

using namespace std;

//Scrie o funcție care șterge linia și coloana pe care se afl ă minimul (prima apariție) și afișează 
//matricea rămasă. 
//Dacă nu rămâne niciun element, afi șează MATRICE VIDA.

void stergereLinie(int a[100][100], int& n, int m, int lin)
{
    for (int i = lin; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = a[i + 1][j];
        }
    }
    n--;
}

void stergereColoana(int a[100][100], int n, int& m, int col)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = col; j < m - 1; j++)
        {
            a[i][j] = a[i][j + 1];
        }
    }
    m--;
}

void afisareMatrice(int a[100][100], int n, int m)
{
    if (n == 0 || m == 0)
    {
        cout << "Matrice Vida" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        
        cout << endl;
    }
}


void stergereLinieColMinim(int a[100][100], int& n, int& m)
{
    int mn = a[0][0], linMin = 0, colMin = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] < mn)
            {
                mn = a[i][j];
                linMin = i;
                colMin = j;
            }
        }
    }

    stergereLinie(a, n, m, linMin);
    stergereColoana(a, n, m, colMin);
    afisareMatrice(a, n, m);
}

void sol1()
{
    // Caz 1
    int a[100][100] = {
        {4, 9, 2},
        {7, 1, 5},
        {8, 3, 6}
    };
    int n1 = 3, m1 = 3;
    stergereLinieColMinim(a, n1, m1);
    cout << endl;

    // Caz 2
    int b[100][100] = {
        {1, 5},
        {7, 2}
    };
    int n2 = 2, m2 = 2;
    stergereLinieColMinim(b, n2, m2);
    cout << endl;

    //Caz 3
    int c[100][100] = {
        {3}
    };
    int n3 = 1, m3 = 1;
    stergereLinieColMinim(c, n3, m3);
}


//Scrie o funcție care șterge toate liniile care nu au elementele ordonate 
//(nici crescător, nici descrescător).Dacă nu rămâne nicio linie, afi șează MATRICE VIDA.

bool linieOrdonata(int a[100][100], int lin, int m)
{
    bool cresc = true, desc = true;

    for (int j = 0; j < m - 1; j++)
    {
        if (a[lin][j] > a[lin][j + 1])
        {
            cresc = false;
        }
        if (a[lin][j] < a[lin][j + 1])
        {
            desc = false;
        }
    }

    return cresc || desc;
}

void stergereLiniiNeordonate(int a[100][100], int& n, int m)
{
    for (int i = 0; i < n; i++)
    {
        if (!linieOrdonata(a, i, m))
        {
            stergereLinie(a, n, m, i);
            i--;
        }
    }
    afisareMatrice(a, n, m);
}

void sol2()
{
    // Caz 1
    int a[100][100] = {
        {1, 2, 3},
        {5, 1, 4},
        {2, 8, 3},
        {9, 7, 2}
    };
    int n1 = 4, m1 = 3;
    stergereLiniiNeordonate(a, n1, m1);
    cout << endl;

    
    // Caz 2
    int b[100][100] = {
        {1, 3, 2}
    };
    int n2 = 1, m2 = 3;
    stergereLiniiNeordonate(b, n2, m2);
}

#endif

