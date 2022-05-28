/* Copy input to output, replacing each string of one or more blanks by a single blank */

#include <stdio.h>

main() {

        int c, last_was_tab;

        last_was_tab = 0;

        while ((c = getchar()) != EOF) {

                /* If c is not a blank, then we certainly want to print it */
                if (c != ' ') {
                        putchar(c);
                        last_was_tab = 0;
                }
                /* If c is a blank then we only want to print it if the last char we printed was not a blank */
                if (c == ' ') {
                        if (last_was_tab == 0) {
                                putchar(c);
                                last_was_tab = 1;
                        }
                }
        }
}
