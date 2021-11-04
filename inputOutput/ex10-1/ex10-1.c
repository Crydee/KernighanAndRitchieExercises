#include <stdio.h>

/* A program that copies its input to its output, replacing each tab by \t, each backspace by \b, and each backslash by \\ */

main()
{
float c;
int has_put;
has_put = 0;

while(( c = getchar()) != EOF) {

        if( c == '\t') {
                printf("\\t");
                has_put = 1;
        }
        if( c == '\b') {
                printf("\\b");
                has_put = 1;
        }
        if( c == '\\') {
                printf("\\\\");
                has_put = 1;
        }

        if( has_put != 1 ) {
                putchar(c);
        }

        has_put = 0;

}
}