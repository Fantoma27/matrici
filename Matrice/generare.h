#ifndef GENERARE_H_INCLUDED
#define GENERARE_H_INCLUDED
#include <iostream>
#include <fstream>

using namespace std;

void afisare(int a[100][100], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

//Partea 1:
//Figura 1:
//1 2 3 4 5 6                 00=1 01=2 
//1 2 3 4 5 6
//1 2 3 4 5 6
//1 2 3 4 5 6
//1 2 3 4 5 6
//1 2 3 4 5 6

void generare1(int n)
{
    int a[100][100];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            a[i][j] = j + 1;
        }
    }
    afisare(a, n, n);
}

//Figura 2:
//    0  1  2  3  4 5

//0   1  2  3  4  5  6          00= 1  01=2  03=3         
//1   2  4  6  8 10 12          10= 2  11=4  12=6        a[i][j]= (i+1)*(j+1)
//2   3  6  9 12 15 18 
//3   4  8 12 16 20 24
//4   5 10 15 20 25 30
//5   6 12 18 24 30 36

void generare2(int n)
{
    int a[100][100];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            a[i][j] = (i + 1) * (j + 1);
        }
    }
    afisare(a, n, n);
}

//Figura 3:      11                12                13                14                15 
// 0 1 0 1 0 1   1 + 1 = 2 % 2 = 0 1 + 2 = 3 % 2 = 1 1 + 3 = 4 % 2 = 0 1 + 4 = 5 % 2 = 0 1 + 5 = 6 % 2 = 0
// 1 0 1 0 1 0   
// 0 1 0 1 0 1   
// 1 0 1 0 1 0
// 0 1 0 1 0 1
// 1 0 1 0 1 0

void generare3(int n)
{
    int a[100][100];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
             a[i][j] = (i + j) % 2;
        }
    }
    afisare(a, n, n);
}

//Figura 4:
//    0  1  2  3  4  5
                                                            
//0   1  2  3  4  5  6     00 01 02 03 04 05              
//1   7  8  9 10 11 12     10 11 12 13 14 15            10=7  11=8   12=    a[i][j]=i*n+j+1
//2  13 14 15 16 17 18     20 21 22 23 24 25
//3  19 20 21 22 23 24     30 31 32 33 34 35
//4  25 26 27 28 29 30     40 41 42 43 44 45
//5  31 32 33 34 35 36     50 51 52 53 54 55

void generare4(int n)
{
    int a[100][100];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            a[i][j] = i * n + j + 1;
        }
    }
    afisare(a, n, n);
}

//Figura 5:
//   0  1  2  3  4  5

//0  1  7 13 19 25 31    
//1  2  8 14 20 26 32
//2  3  9 15 21 27 33
//3  4 10 16 22 28 34
//4  5 11 17 23 29 35
//5  6 12 18 24 30 36

void generare5(int n)
{
    int a[100][100];
    for(int j = 0; j < n; j++)
    {
        for(int i = 0; i < n; i++)
        {
            a[i][j] = j * n + i + 1;
        }
    }
    afisare(a, n, n);
}

//Partea 2:
//Figura 6:
//   0 1 2 3 4 5

//0  1 1 1 1 1 1        00 =1    11=2 
//1  1 2 2 2 2 2
//2  1 2 3 3 3 3
//3  1 2 3 4 4 4
//4  1 2 3 4 5 5
//5  1 2 3 4 5 6

void generare6(int n)
{
    int a[100][100];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            a[i][j] = i + 1;
            if(j + 1 < a[i][j])
            {
                a[i][j] = j + 1;
            }
        }
    }
    afisare(a, n, n);
}

// Figura 7:
//   0 1 2 3 4 5

//0  1 2 3 4 5 6    i > j   a[i][j] = i + 1
//1  2 2 3 4 5 6    
//2  3 3 3 4 5 6
//3  4 4 4 4 5 6    j > i   a[i][j] = j + 1
//4  5 5 5 5 5 6
//5  6 6 6 6 6 6

void generare7(int n)
{
    int a[100][100];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            a[i][j] = i + 1;
            if(j + 1 > a[i][j])
            {
                a[i][j] = j + 1;
            }
        }
    }
    afisare(a, n, n);
}
void generare7_1(int n)
{
    int a[100][100];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i > j)
            {
                a[i][j] = i + 1;
            }
            else
            {
                a[i][j] = j + 1;
            }
        }
    }
    afisare(a, n, n);
}



#endif