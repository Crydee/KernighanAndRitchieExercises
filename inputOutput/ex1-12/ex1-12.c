#include <stdio.h>

#define IN 1
#define OUT 0
/* A program that prints its input one word per line. */

main() {

int state, c;
state = OUT;

while ((c = getchar()) != EOF) {
    if ( c != ' ' && c != '\n' && c != '\t') {
        putchar(c);
        state = IN;
    } else if (state == IN) {
        putchar('\n');
        state = OUT;
    }
}
putchar('\n');
}
