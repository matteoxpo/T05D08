#include <stdio.h>
#include <math.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        squaring(data, n);
        output(data, n);
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
    printf("%d", *(a + n - 1));
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++)
        (*p) = (*p)*(*p);
}


