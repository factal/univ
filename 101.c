#include <stdio.h>

void print_data(int n, double data[n]) {
    for (int i = 0; i < n; i++) {
        printf("%f, ", data[i]);
    }
    printf("\n");
}

void swap (double *x, double *y) {
    double temp = *x;
    *x = *y;
    *y = temp;
}

void bubble_sort(int n, double data[n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (data[j] > data[j + 1]) {
                swap(&data[j], &data[j + 1]);
                print_data(n, data);
            }
        }
    }
}

int main() {
  double data[] = { 5.0, 3.0, 1.0, 2.0, 4.0 };
  int n = sizeof(data) / sizeof(data[0]);
  print_data(n, data);
  bubble_sort(n, data);
  return 0;
}
