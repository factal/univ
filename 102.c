#include <stdio.h>

void print_data(int n, double data[n]) {
    for (int i = 0; i < n; i++) {
        printf("%.0f, ", data[i]);
    }
    printf("\n");
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

int main() {
    double data[] = { 1, 3, 4, 3, 5, 5, 2, 4 };
    int n = sizeof(data) / sizeof(data[0]);
    print_data(n, data);
    quick_sort(n, data);
    print_data(n, data);
}
