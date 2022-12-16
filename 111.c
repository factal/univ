#include <stdlib.h>
#include <stdio.h>

int TOTAL = 100;

void read_data_file(double *data) {
    int i, scannum;

    FILE *fp = fopen("d111.txt", "r");
    if (fp == NULL) {
        printf("Error: cannot open file d111.txt");
        exit(1);
    }

    for (int i = 0; i < TOTAL; i++) {
        scannum = fscanf(fp, "%lf", &data[i]);
        if (scannum != 1) {
            fprintf(stderr, "Error: cannot read data from file d111.txt");
            exit(1);
        }
    }

    fclose(fp);
}

void quick_sort_base(int n, double data[n], int l, int r) {
    if (l < r) {
        int i = l;
        int j = r;
        double pivot = data[(l + r) / 2];

        printf("sorting [%d] ... [%d], pivot = [%d]: %.0f\n", l, r, (l + r) / 2, pivot);

        while (i <= j) {
            while (data[i] < pivot) {
                i++;
            }
            while (data[j] > pivot) {
                j--;
            }
            if (i <= j) {

                printf("swapped [%d]: %.0f <---> [%d]: %.0f\n", i, data[i], j, data[j]);

                double temp = data[i];
                data[i] = data[j];
                data[j] = temp;
                i++;
                j--;
            }
        }
        quick_sort_base(n, data, l, j);
        quick_sort_base(n, data, i, r);
    }
}

void quick_sort(int n, double data[n]) {
    if (n >= 2) {
        quick_sort_base(n, data, 0, n - 1);
    }
}

void print_data(int n, double data[n]) {
    for (int i = 0; i < n; i++) {
        printf("%.0f, ", data[i]);
    }
    printf("\n");
}

int main() {
    double data[TOTAL];
    read_data_file(data);
    quick_sort(TOTAL, data);
    print_data(TOTAL, data);

    return 0;
}
