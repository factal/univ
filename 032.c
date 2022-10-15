#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int a[3][3] = {
        {2, 4, 6},
        {3, 8, 7},
        {5, 7, 21}
    };

    int x[3] = {-33, 9, 6};

    double *ai;

    ai = a[0];
    for (int i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", *ai);
            ai++;
        }
        
        ai += 3;
    }

    return 0;
}