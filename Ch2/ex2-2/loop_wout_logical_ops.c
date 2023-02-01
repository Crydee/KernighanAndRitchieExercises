#include <stdio.h>

main() {
}

int get_line(char line[], int lim)
{
    int c, ii;

    ii = 0;
    while (ii < lim - 1) {
            if ((c = getchar()) != '\n') {
                    if(c != EOF) {
                        line[ii] = c;
                        ii++;
                    } else {
                            line[ii] = '\0';
                            ii = lim - 1;
                    }
            } else {
                 line[ii] = c;
                 line[ii++] = '\0';
                 ii = lim - 1;
             }
    }
    /* Currently this isn't great as ii is no-longer reliably the length of the line. */
    return ii;
}
