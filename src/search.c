#include <stdio.h>
#include <math.h>
#define NMAX 30
//#define sigma(D) return sqrt(D);

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
double sigma(double D);
int search(int *a, int n);
int treeSigmRule(int *a,int n, int *el);
int main() {
    int n, data[NMAX];
    if (input(data, &n)) { 
        printf("%d", search(data, n));
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

double sigma(double D){ return sqrt(D); }

int treeSigmRule(int *a, int n, int *el) {
    if (*el - mean(a, n) <= 3 * sqrt(variance(a, n))){
        return 1;
        //printf("%d", *el);
    } else {
        return 0;
        printf("%d", *el);
    }
}

int search(int *a, int n) {
    double M = mean(a, n);
    for (int *p = a; p - a < n; p++) {          //&& treeSigmRule(a, n, p)
        if (*p % 2 == 0 && *p != 0 && *p >= M && treeSigmRule(a, n, p)) {
            return *p;
        }
    }
    return 0;
}
