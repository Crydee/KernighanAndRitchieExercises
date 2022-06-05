#include <stdio.h>

/* A program that prints its input one 'word' per line, where a 'word' is a continuous sequence of */
/* non-whitespace characters */

main() {

int c;

while ((c = getchar()) != EOF) {
    if ((c != ' ') && (c != '\n') && (c != '\t')) {
        /* We always want to just print non-whitespace characters. */
        putchar(c);
    } else {
        putchar('\n');
        while (((c = getchar()) != EOF) && ((c == ' ') || (c == '\n') || (c == '\t')))
        /* Here the last char we printed was a new-line.  We don't want to print more newlines until we have */
        /* printed another 'word'. */
        ;
        if (c != EOF)
            putchar(c);
    }
}
putchar('\n');
}
