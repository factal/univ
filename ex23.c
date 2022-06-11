#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
    int i, xi[16];

    srand(time(NULL));

    for ( i=0; i<16; i++ ) {
        xi[i] = rand() % 10;
        printf("xi[%2d] = %d\n", i, xi[i]);
    }

    return 0;
}

/*
(base) keter@keternoMacBook-Air univ % ./ex28
xi[ 0] = 1
xi[ 1] = 9
xi[ 2] = 2
xi[ 3] = 9
xi[ 4] = 3
xi[ 5] = 4
xi[ 6] = 4
xi[ 7] = 0
xi[ 8] = 6
xi[ 9] = 6
xi[10] = 3
xi[11] = 6
xi[12] = 6
xi[13] = 8
xi[14] = 2
xi[15] = 5
*/