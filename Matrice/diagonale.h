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

int sumaDeasupraPrincipala(int a[100][100], int n)
{
    int s = 0;
    int ct = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            s += a[i][j];
            ct++;
        }
    }
    if(ct == 0)
    {
        return -1;
    }
    return s / ct;

}

/*void verif()
{
    int a[100][100] = {
        {1, 2, 5},
        {4, 5, 6},
        {7, 8, 9}
    };
    int n = 3;
    int ma1;
    sumaDeasupraPrincipala(a, n, ma1);
    cout << ma1;
}*/

int cateElemMaiMareDecatDeasupraPrincipalei(int a[100][100], int n)
{
    int ma;
    int ct = 0;
    ma = sumaDeasupraPrincipala(a, n);
    if(ma == -1)
    {
        return -1;
    }
    for(int i = 0; i < n; i++)
    {
        if(a[i][i] > ma)
        {
            ct++;
        }
    }
    return ct;
}

void sol3()
{
    cout << "Caz 1:" << endl;
    int a[100][100] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int n1 = 3;
    cout << cateElemMaiMareDecatDeasupraPrincipalei(a, n1) << endl;

    cout << "Caz 2:" << endl;
    int b[100][100] = {
        {5, 9, 1},
        {2, 5, 8},
        {7, 3, 5}
    };
    int n2 = 3;
    cout << cateElemMaiMareDecatDeasupraPrincipalei(b, n2) << endl;

    cout << "Caz 3:" << endl;
    int c[100][100] = {
        {7}
    };
    int n3 = 1;
    cout << cateElemMaiMareDecatDeasupraPrincipalei(b, n3) << endl;;

}

//Zonele fără diagonale: Nord (deasupra ambelor diagonale), Sud (sub ambele), Est (la dreapta), 
//Vest (lastânga). Scrie o funcție care afișează zona cu suma cea mai mare și suma ei. 
//La egalitate, în ordinea Nord, Sud, Est, Vest.

int nord(int a[100][100], int n)
{
    int s = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n - 1 - i; j++)
        {
            s += a[i][j];
        }
    }
    return s;
}

int sud(int a[100][100], int n)
{
    int s = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = n - 1; j < i; j++)
        {
            s += a[i][j];
        }
    }
    return s;
}

int est(int a[100][100], int n)
{
    int s = 0;
    for(int j = 0; j < n; j++)
    {
        for(int i = n - j; i < j + 1; j++)
        {
            s += a[i][j];
        }
    }
    return s;
}

int vest(int a[100][100], int n)
{
    int s = 0;
    for(int j = 0; j < n; j++)
    {
        for(int i = j + 1; i < n - 1 - j; i++)
        {
            s += a[i][j];
        }
    }
    return s;
}


void sol4()
{
    cout << "Caz 1:" << endl;
    int a[100][100] = {
        {1, 2, 3. 4. 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}.
        {16, 17, 18, 19, 20}.
        {21, 22, 23, 24, 25}
    };
    int n1 = 3;
    int n, s, e, v;
    n = nord(a, n);
    s = sud(a, n);
    e = est(a, n);
    v = vest(a, n);
    int maxx = -1;
    int v[10];
    v[0] = n;
    v[1] = s;
    v[2] = e;
    v[3] = v;
    for(int i = 0; i < n; i++)
    {
        if(v[i] > maxx)
        {
            maxx = v[i];

        }
        else if(v[i] == max)
        {
            
        }
    }






    cout << "Caz 2:" << endl;
    int b[100][100] = {
        {5, 9, 1},
        {2, 5, 8},
        {7, 3, 5}
    };
    int n2 = 3;



}




#endif