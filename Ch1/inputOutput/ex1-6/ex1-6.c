#include <stdio.h>

/* Verify that the expr. getchar() != EOF is 0 or 1 */

main() {
        int c;

        while ((c = (getchar() != EOF)))
                printf("The value of c is: %d\n", c);

        printf("The value of c is: %d\n", c);

}
