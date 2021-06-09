#include <stdio.h>
#define NMAX 10

void input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

void main()
{
    int n, data[NMAX];
    input(data, n);
    output(data, n);
    squaring(data, n);
    output(data, n); 
}

void input(int *a, int *n)
{
    scanf("%d", n);
    for(int *p = a; p - a < *n; p++)
    {
        scanf("%d", p);
    }
}

void output(int *a, int n)
{
    //NOTHING
}

void squaring(int *a, int n)
{
    //NOTHING
}


