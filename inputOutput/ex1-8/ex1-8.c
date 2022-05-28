/* Count blanks, tabs, and newlines */

#include <stdio.h>

main() {
        long nb, nt, nl; /* Variables to hold the num. of blanks, tabs and new-line chars resp. */
        int c;

        for (nb = nt = nl = 0; (c = getchar()) != EOF;) {

                if (c == ' ')
                        ++nb;
                if (c == '\t')
                       ++nt;
                if (c == '\n')
                       ++nl;

        }
     
        printf("The number of blanks was: %ld\n", nb);
        printf("The number of tabs was: %ld\n", nt);
        printf("The number of newlines was: %ld\n", nl);


        

}
