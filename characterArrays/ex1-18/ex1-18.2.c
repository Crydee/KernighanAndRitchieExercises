#include <stdio.h>

#define MAXWSPACE 1000 /* The program can handle sequences of consecutive spaces or tabs up to this many chars in length */

void zero_arr(char arr[], int length);

/* A program to remove trailing whitespace and lines that contain only whitespace */ 
main() 
{
        char cons_spaces_tabs[MAXWSPACE + 1]; /* stores up to the MAXWSPACE consecutive tabs or space, null-terminated */
        int i, c, got_non_whitespace;

        i = got_non_whitespace = 0;

        while ((c = getchar()) != EOF) {
                if (c == ' ' || c == '\t') {
                        if (i < MAXWSPACE) {
                                cons_spaces_tabs[i] = c;
                                i++;
                        }
                        else {
                                cons_spaces_tabs[i] = '\0';
                                printf("ERROR: encountered a sequence of spaces or tabs longer than %d characters", MAXWSPACE);
                                return 1;
                        }
                }
                else if (c == '\n') 
                {
                        if (got_non_whitespace == 1)
                        {
                                /* We've reached the end of the line, so discard any preceding whitespace and print '\n' */
                                putchar(c);
                                got_non_whitespace = 0;
                        }
                        /* Wether or not we encountered any non-whitespace chars in the line, we always want to zero the array at the end of the line */
                        zero_arr(cons_spaces_tabs, i + 1);
                        i = 0;
                }
                else 
                {
                        /* We get a non-whitespace character before getting MAXWSPACE consecutive tabs or spaces,
                                * and before the end of the line, so null-terminate the arr of whitespace, print its
                                * contents up to the null, zero the array and then print the non-whitespace character. */
                        got_non_whitespace = 1;
                        cons_spaces_tabs[i] = '\0'; 
                        printf("%s", cons_spaces_tabs);
                        zero_arr(cons_spaces_tabs, i + 1);
                        putchar(c);
                        i = 0; /* Zeroed, ready for the next whitespace char we get */
                }
        }
}


/* Zero an array of with length elts */
void zero_arr(char arr[], int length) { 
        int index;
        for (index = 0; index < length; index++)
                arr[index] = 0;
}


