#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int i_max;
    printf("i_max = ");
    scanf("%d", &i_max);

    for (int i = 10; i <= i_max; i++) {
        printf("i = %d\t i ** 2 = %d\n", i, i * i);
    }

    return 0;
}

/*
(base) keter@keternoMacBook-Air univ % ./ex17
i_max = 2
(base) keter@keternoMacBook-Air univ % ./ex17
i_max = 15
i = 10   i ** 2 = 100
i = 11   i ** 2 = 121
i = 12   i ** 2 = 144
i = 13   i ** 2 = 169
i = 14   i ** 2 = 196
i = 15   i ** 2 = 225
*/