#include <stdlib.h>
#include <stdio.h>

int N = 1000;

// double* buf: [student_id, score A, score B, score C, ...]
double buff[1000][5];

void read_file(int n, double buff[n][5]) {
    int i, scannum;

    FILE *file = fopen("rep_data.txt", "r");
    if (file ==  NULL) {
        fprintf(stderr, "cannot open file\n");
        exit(1);
    }

    for (i = 0; i < n; i++) {
        // scannum = fscanf(file, "%lf", &buff[i]);
        for (int j = 0; j < 4; j++) {
            scannum = fscanf(file, "%lf", &buff[i][j]);
            if (scannum != 1) {
                fprintf(stderr, "cannot read file\n");
                exit(1);
            }
        }
    }

    fclose(file);
}

int binary_search(int n, double buff[n][5], int index, double key) {
    int l = 0;
    int r = n-1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (buff[m][index] == key) {
            return m;
        } else if (buff[m][index] < key) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}

void calc_sum(int n, double data[n][5]) {
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 1; j < 4; j++) {
            sum += data[i][j];
        }
        data[i][4] = sum;
    }
}

void quick_sort_base(int n, double data[n][5], int l, int r) {
    if (l < r) {
        int i = l;
        int j = r;
        double pivot = data[(l + r) / 2][4];

        while (i <= j) {
            while (data[i][4] < pivot) {
                i++;
            }
            while (data[j][4] > pivot) {
                j--;
            }
            if (i <= j) {
                double temp[5];
                for (int k = 0; k < 5; k++) {
                    temp[k] = data[i][k];
                    data[i][k] = data[j][k];
                    data[j][k] = temp[k];
                }
                i++;
                j--;
            }
        }
        quick_sort_base(n, data, l, j);
        quick_sort_base(n, data, i, r);
    }
}

void quick_sort(int n, double data[n][5]) {
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
    read_file(N, buff);
    calc_sum(N, buff);

    int number;
    printf("Input A Student Number: ");
    scanf("%d", &number);
    
    int num = binary_search(N, buff, 0, number);
    double sum = buff[num][4];

    quick_sort(N, buff);
    int res = binary_search(N, buff, 4, sum);
    
    if (res == -1) {
        printf("No Data\n");
        return 0;
    }

    printf("Ranking\t: #%d\n", 1000 - res);
    printf("Subject A\t: %.0f\n", buff[res][1]);
    printf("Subject B\t: %.1f\n", buff[res][2]);
    printf("Subject C\t: %.2f\n", buff[res][3]);
    printf("Total\t: %.2f\n", buff[res][4]);

    return 0;
}
