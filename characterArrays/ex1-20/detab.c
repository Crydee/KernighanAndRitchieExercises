/* ex1-20 Write a program detab that replaces tabs in the input
 * with the proper number of blanks to space to the next tab stop.
 * Assume a fixed set of tab stops, say every n columns.*/

#include <stdio.h>
#define STOPLEN 10

int how_far(int position, int spacing);

int main() {

    int c, distance, position, i;
    /* position: the number of spaces from the last tab stop */

    position = 0;

    while((c=getchar()) != EOF) {
        if(c == '\t') {
            distance = how_far(position, STOPLEN);
            for(i=0; i < distance ; ++i) {
                printf(" ");
            }
            position = 0;        
        }
        else {
            printf("%c", c);
            position = (position + 1) % STOPLEN;            
        }
    }
    return 0;
}

/* how_far: for a given position in a line and spacing between tab stops
 * , return the number of spaces to the next tab stop. */
int how_far(int position, int spacing) {
    return spacing - (position % spacing); 
}
