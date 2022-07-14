#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int c;
    char infile[] = "elements.dat";
    FILE *fp;

    if ((fp = fopen(infile, "r")) == NULL) {
        printf("Can't open %s\n", infile);
        exit(0);
    }

    while ((c = fgetc(fp)) != EOF) {
        fputc(c, stdout);
        fflush(stdout);
        usleep(10000);
    }

    fclose(fp);

    return 0;
}