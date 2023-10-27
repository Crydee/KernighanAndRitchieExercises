/* ex1-20 Write a program detab that replaces tabs in the input
 * with the proper number of blanks to space to the next tab stop.
 * Assume a fixed set of tab stops, say every n columns.*/

#include <stdio.h>
#define STOPLEN 10 /* The number of spaces between tab-stops. */

int how_far(int position, int spacing);

int main() {

    int c, position, i;
    /* position: the number of spaces from the last tab stop */

    position = 0;

    while((c=getchar()) != EOF) {
        if(c == '\t') {
            for(i=0; i < how_far(position, STOPLEN) ; ++i) {
                printf(" ");
            }
            position = 0;        
        }
        else {
            if (c == '\n')
            {
                position = 0;
            }
            else
            {
                position = (position + 1) % STOPLEN;                 
            }
            printf("%c", c);
        }
    }
    return 0;
}

/* how_far: for a given position in a line and spacing between tab stops
 * , return the number of spaces to the next tab stop. */
int how_far(int position, int spacing) {
    return spacing - (position % spacing); 
}
