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

#endif