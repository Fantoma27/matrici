#ifndef PARCURGERE_H_INCLUDED
#define PARCURGERE_H_INCLUDED
#include <iostream>
#include <fstream>

using namespace std;

//1: Scrie o funcție care afisează linia cu cea mai mare sumă 
//a elementelor și suma ei. La egalitate, prima linie.

int sumaLinie(int a[100][100], int n, int m, int l)
{
    int suma = 0;
    for(int j = 0; j < m; j++)
    {
        suma = suma + a[l][j];
    }
    return suma;
}

int linieMax(int a[100][100], int n, int m)
{
    int l;
    int maxx = sumaLinie(a, n, m, 0);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int suma = sumaLinie(a, n, m, i);
            if(suma > maxx)
            {
                maxx = suma;
                l = i;
            }
        }
    }
    for(int j = 0; j < m; j++)
    {
        cout << a[l][j] << ' ';
    }
}


void sol11(){

    int a[100][100]={{5 , 121, 16, 16, 121, 5},
                     {12, 233, 21, 13, 49, 31}, 
                     {-5 ,110 ,37 ,1331 ,5 ,8},
                      {3 ,44 ,10 ,239 ,7 ,2} };
    int n = 4, m = 6;
    linieMax(a, n, m);
}

//2:Scrie o funcție care întoarce câte coloane au elementele ordonate,
// crescător sau descrescător. O coloană constantă se numără o singură dată.

bool coloaneOrdonate(int a[100][100], int n, int m)
{

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] > a[i][j + 1])
            {
                return false;
            }
        }
    }
    return true;
}

void cateColoane(int a[100][100], int n, int m);
{
    int ct = ;
    for(int i = 0; i < n; j++)
    {
        for(int j = 0; j < m; j++)
        {
            if(coloaneOrdonate(a, n, j));
            {
                ct++;
            }
        }
    }
}

void sol22()
{
    int a[100][100] = {
        {1, 2, 3},
        {4, 6, 8},
        {5, 7, 2}
    };
    int n = 3;
    int m = 3;
}


#endif