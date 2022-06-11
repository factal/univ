#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
    char c;

    while (1) {    
        printf("Input a character: ");
        scanf(" %c", &c);\
        if (c == 'q' || c == 'Q') break;
        printf("You entered %c\n", c);
    }

    printf("Bye\n");

    return 0;
}