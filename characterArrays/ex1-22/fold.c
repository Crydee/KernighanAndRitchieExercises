/* Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character */
/* that occurs before the n'th column of input. Make sure your program does something intelligent with very long */
/* lines, and if there are no blanks or tabs before the specified column. */

#include <stdio.h>

#define FOLD_BEFORE 10 /* We fold lines after the last non-blank character that occurs before the FOLD_BEFORE'th
                        * column. */
#define MAX_LINE_LEN 1000 /* The maximum length of an input line that the function will accept without complaint. */

#define TRUE 1
#define FALSE 0 

int fold_before_lim(char line[], int lim);
int get_line(char line[], int lim);

int main()
{
    char line[MAX_LINE_LEN + 1];

    get_line(line, MAX_LINE_LEN);

    fold_before_lim(line, FOLD_BEFORE);
}

/* A function to print a null-terminated input array as either one line, or several folded lines.  The folding occurs after */
/* the last non-blank character that occurs before a  +ve multiple of the fold_before'th element. */
int fold_before_lim(char line[], int lim)
{
    int c, done, ii, print_to, printed_to, lines_printed;

    printed_to = -1;
    done = FALSE;

    for (lines_printed = 0; done == FALSE; lines_printed++)
    {
        for (ii = printed_to + 1; (ii <= (printed_to + (lim - 1))) && (done == FALSE); ii++)
        {
            if (((c = line[ii]) == '\n') || (c == '\0'))
            {
                done = TRUE;
            }
            else if ((c != ' ') && (c != '\t'))
            {
                /* The element is a non-blank character, so we could fold the line after it. */
                print_to = ii;

            }
        }
    }
    /* The inner loop has finished, so we want to print the elements in (printed_to, print_to] and then update printed_to. */
    for (ii = (printed_to + 1); ii <= print_to; ii++)
    {
        printf("%c", line[ii]);
    }
    printed_to = print_to;
}

int get_line(char line[], int lim)
{
    int c, ii;

    for (ii = 0; (ii < lim - 1) && ((c = getchar()) != EOF) && (c != '\n'); ii++)
    {
        line[ii] = c;
    }

    if (c == '\n')
    {
        line[ii] = c;
        ii++;
    }

    line[ii] = '\0';

    return ii;
}
