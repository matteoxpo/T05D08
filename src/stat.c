#include <stdio.h>
#include <math.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
    output(data, n);
    output_result(max(data, n),
                  min(data, n),
                  mean(data, n),
                  variance(data, n));
    } 
    return 0;
}

int input(int *a, int *n ) {
    char c = 0;
    if (scanf("%d%c", n, &c) && c == '\n' && *n >= 0 && *n <= NMAX) {
        for (int *p = a; p - a < *n; p++)
            if (scanf("%d%c", p, &c) && (c == ' ' || c == '\n' || c == EOF)) {
                continue;
            } else {
                printf("n/a");
                return 0;
            }
    } else {
        printf("n/a");
        return 0;
    }
    return 1;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n - 1; p++)
        printf("%d ", *p);
    printf("%d\n", *(a + n - 1));
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
  printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}

int max(int *a, int n) {
    int max = *a;
    for (int *p = a + 1; p - a < n; p++)
        if (*p > max)
            max = *p;
    return max;
}

int min(int *a, int n) {
    int min = *a;
    for (int *p = a + 1; p - a < n; p++)
        if (*p < min)
            min = *p;
    return min;
}


double mean(int *a, int n) {
    double M = 0;
    for (int *p = a; p - a < n; p++){
        M += ((double)(*p))/n;
    }
    return M;
}

double variance(int *a, int n) {
    double M = mean(a, n);
    double D = 0;
    for (int *p = a; p - a < n; p++)
        D += pow(*p - M, 2)/n;
    return D;
}
