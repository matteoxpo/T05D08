#include <stdio.h>
#define NMAX 10

void input(double *a, int *n);
void output(double *a, int n);
double max(double *a, int n);
double min(double *a, int n);
double mean(double *a, int n);
double variance(double *a, int n);

void output_result(double max_v,
                   double min_v,
                   double mean_v,
                   double variance_v);

void main()
{
    int n, data[NMAX];
    input(data, n);
    output(data, n);
    output_result(max(data, n),
                  min(data, n),
                  mean(data, n),
                  variance(data, n));
}


