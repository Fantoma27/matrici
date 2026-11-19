#ifndef MATRICE_H_INCLUDED
#define MATRICE_H_INCLUDED

#include <iostream>
#include <fstream>

using namespace std;

void citire(int a[100][100], int& n, int& m)
{
    ifstream fin("matrice.in");
    if (!fin.is_open())
    {
        cout << "matrice.in lipseste" << endl;
        n = 0;
        m = 0;
        return;
    }
    fin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fin >> a[i][j];
        }
    }
}

void afisare(int a[100][100], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void scriere(int a[100][100], int n, int m)
{
    ofstream fout("matrice.out");
    fout << n << " " << m << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fout << a[i][j] << " ";
        }
        fout << endl;
    }
}

#endif // MATRICE_H_INCLUDED
