#include <stdio.h>

double get_avg(int *a, int N) {
    int avg = 0;
    int i;

    for (i = 0; i< N; i++) {
        avg += a[i];
    }
    avg /= N;

    return avg;
}

int main(void) {
    int i;
    int a[10] = {3, 5, 8, 9, 10, 6, 7, 9, 8, 3};
    double avg;

    avg = get_avg(a, 10);

    printf("average = %.2f\n", avg);

    return 0;
}