/* Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character */
/* that occurs before the n'th column of input. */

#include <stdio.h>

#define FOLD_BEFORE 100 /* We fold lines after the last non-blank character that occurs before the FOLD_BEFORE'th
                         * column. */
#define MAX_LINE_LEN 1000 /* The maximum length of an input line that the function will accept without complaint. */

#define TAB_STOP_SPACING 4 /* The number of spaces between consecutive tab-stops. */

int get_line(char line[], int lim);

int main()
{
    int len;
    char input_line[MAX_LINE_LEN + 1];

    while ((len = get_line(input_line, MAX_LINE_LEN + 1)) != 0)
    {
        printf("The length of that line is %d", len);
    }
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
