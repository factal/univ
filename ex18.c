#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 8; j++) {
            int n = 8 * i + j;
            printf("%3d (x%02x)", n, n);
        }
        printf("\n");
    }

    return 0;
}