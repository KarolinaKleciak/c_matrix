#include <stdio.h>
#include <stdlib.h>

void wyswietl_macierz(int *macierz, int m, int n)
{
    int i,j;

    printf("\n");

    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d ", *(&macierz[j]+i*m));
        }
        printf("\n");
    }
}

int dodawanie_macierzy(int *macierz1, int *macierz2, int *macierz3, int m, int n)
{
    int i,j;

    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            *(&macierz3[j]+i*m) = *(&macierz1[j]+i*m) + *(&macierz2[j]+i*m);
        }
    }
}

void odejmowanie_macierzy(int *macierz1, int *macierz2, int *macierz3, int m, int n)
{
    int i, j;

    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            *(&macierz3[j]+i*m) = *(&macierz1[j]+i*m) - *(&macierz2[j]+i*m);
        }
    }
}

void mnozenie_macierzy(int *macierz1, int *macierz2, int *macierz3, int m, int n)
{
    int i, j, k;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            *(&macierz3[j]+i*m) = 0;

            for (k = 0; k < n; k++)
            {
                *(&macierz3[j]+i*m) += *(&macierz1[k]+i*n) * *(&macierz2[j]+k*m);
            }
        }
    }
}

int main()
{
    int i, j;
    int m1[3][3] = {{1, 2, 5}, {4, 7, 5}, {3, 7, 2}};
    int m2[3][3] = {{5, 6, 7}, {8, 9, 10}, {4, 2, 8}};
    int m3[3][3];
    int m4[4][3] = {{3, 5, 7}, {6, 3, 2}, {7, 2, 9}, {6, 3, 9}};
    int m5[3][4] = {{5, 7, 6, 2}, {5, 3, 2, 8}, {4, 3, 0, 7}};
    int m6[4][4];

    printf("\nDODAWANIE MACIERZY:\n");
    wyswietl_macierz(&m1[0][0], 3, 3);
    wyswietl_macierz(&m2[0][0], 3, 3);
    dodawanie_macierzy(&m1[0][0], &m2[0][0], &m3[0][0], 3, 3);
    wyswietl_macierz(&m3[0][0], 3, 3);
    printf("\nODEJMOWANIE MACIERZY:\n");
    wyswietl_macierz(&m1[0][0], 3, 3);
    wyswietl_macierz(&m2[0][0], 3, 3);
    odejmowanie_macierzy(&m1[0][0], &m2[0][0], &m3[0][0], 3, 3);
    wyswietl_macierz(&m3[0][0], 3, 3);
    printf("\nMNOZENIE MACIERZY:\n");
    wyswietl_macierz(&m4[0][0], 4, 3);
    wyswietl_macierz(&m5[0][0], 3, 4);
    mnozenie_macierzy(&m4[0][0], &m5[0][0], &m6[0][0], 4, 3);
    wyswietl_macierz(&m6[0][0], 4, 4);
    return 0;
}
