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
        int suma = sumaLinie(a, n, m, i);
            if(suma > maxx)
            {
                maxx = suma;
                l = i;
            }
    }
    for(int j = 0; j < m; j++)
    {
        cout << a[l][j] << ' ';
    }
}


void sol1(){

    int a[100][100]={{5 , 121, 16, 16, 121, 5},
                     {12, 233, 21, 13, 49, 31}, 
                     {-5 ,110 ,37 ,1331 ,5 ,8},
                      {3 ,44 ,10 ,239 ,7 ,2} };
    int n = 4, m = 6;
    linieMax(a, n, m);
}

//2:Scrie o funcție care întoarce câte coloane au elementele ordonate,
// crescător sau descrescător. O coloană constantă se numără o singură dată.

bool coloaneOrdonate(int a[100][100], int n, int col)
{
    bool crescator = true;
    bool descrescator = true;
    for(int i = 0; i < n-1; i++)
    {
        if(a[i][col] > a[i + 1][col])
        {
            crescator = false;
        }
        if(a[i][col] < a[i + 1][col])
        {
            descrescator = false;
        }
    }
    return crescator || descrescator;
}


/*void verif()
{
    int a[100][100] = {
        {1, 9, 5},
        {4, 3, 7},
        {3, 8, 2}
    };
    int n = 3;
    int m = 3;
    cout << coloaneOrdonate(a, n, 2);
}*/

int cateColoane(int a[100][100], int n, int m)
{
     int ct = 0;
     for(int j = 0; j < m; j++)
     {
        if(coloaneOrdonate(a, n, j))
        {
            //cout<<"test"<<endl;
            ct++;
        }
     }
     return ct;
 }

void sol2()
{
    int a[100][100] = {
        {1, 2, 3},
        {4, 6, 8},
        {5, 7, 2}
    };
    int n = 3;
    int m = 3;
   cout<< cateColoane(a, n, m);
}

//Scrie o funcție care întoarce cât de departe sunt minimul și maximul: diferența dintre 
//linii plus diferența dintre coloane, fi ecare fără semn.
// Dacă apar de mai multe ori, se iau primele apariții.

void pozMinim(int a[100][100], int n, int m, int &min_n, int &min_m)
{
    int minn = 1000;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] < minn)
            {
                minn = a[i][j];
                min_n = i;
                min_m = j;
            }
        }
    }
}

void pozMaxim(int a[100][100], int n, int m, int &max_n, int &max_m)
{
    int maxx = -1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] > maxx)
            {
                maxx = a[i][j];
                max_n = i;
                max_m = j;
            }
        }
    }
    
}

/*void verifminmax()
{
    int a[100][100] = {
        {1, 2, 3},
        {4, 9, 8},
        {5, 7, 2}
    };
    int n = 3;
    int m = 3;
    pozMaxim(a, n, m);
}*/

int calcul(int a[100][100], int n, int m)
{
    int min_n, min_m, max_n, max_m;
    pozMaxim(a, n, m, max_n, max_m);
    pozMinim(a, n, m, min_n, min_m);
    return (max_n - min_n) + (max_n - min_m);
}

void sol3()
{
    int a[100][100] = {
        {1, 2, 3},
        {4, 2, 8},
        {5, 7, 9}
    };
    int n = 3;
    int m = 3;
    cout << calcul(a, n, m);
}

//Scrie o funcție care afișează elementul care apare de 
//cele mai multe ori în matrice. La egalitate, cel mai mic.

void  frecventaElementMatrice(int a[100][100], int n, int m, int f[])
{
    int ct = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
             f[a[i][j]]++;
        }
    }
   
}

//functie ce returneaza pozitia maximului dintr-un vecotr
//functie ce returneaza pozitia minimului din vector

int pozMaximVector(int f[])
{
    int maxx = -1;
    for(int i = 0; i < 10; i++)
    {
        if(f[i] > maxx)
        {
            maxx = f[i];
            poz = i;
        }
    }
    return poz;
}

int pozMinimVector(int f[])
{
    int minn = 1000;
    int poz = -1;
    for(int i = 0; i < 10; i++)
    {
        if(f[i] > 0 && f[i] < minn)
        {
            minn = f[i];
            poz = i;
        }
    }
    return poz;
}

// void verifgasire()
// {
//     int a[100][100] = {
//         {1, 2, 3},
//         {4, 9, 8},
//         {5, 9, 9}
//     };
//     int n = 3;
//     int m = 3;
//     cout << gasireElement(a, n, m, 9);
// }

// void sol4()
// {
//     int a[100][100] = {
//         {3, 7, 3},
//         {5, 7, 3}
//     };
//     int n = 2;
//     int m = 3;
//     int maxx = -1;
//     for(int i = 0; i < n; i++)
//     {
//         for(int j = 0; j < m; j++)
//         {
//             if(gasireElement(a, n, m, a[i][j]) > maxx)
//             {
//                 maxx = a[i][j];
//             }
//         }
//     }
//     cout << maxx;
// }

#endif