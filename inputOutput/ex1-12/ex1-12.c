#include <stdio.h>

/* A program that prints its input one word per line. */

main() {

int c;

while ((c = getchar()) != EOF) {
    if ((c != ' ') && (c != '\n') && (c != '\t')) {
        putchar(c);
    } else {
        putchar('\n');
        while (((c = getchar()) != EOF) && ((c == ' ') || (c == '\n') || (c == '\t')))
        ;
        putchar(c);
    }
}
putchar('\n');
}
