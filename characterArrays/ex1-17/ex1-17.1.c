#include <stdio.h>

#define CUTOFF 80 /* We will print lines that are longer than this many characters. */

int get_line(char line[], int maxline);
void print_rest_of_line();

int main()
{
        int len;
        /* An array to store up to the first CUTOFF characters and a null character. */
        char line[CUTOFF + 1];

        while ((len = get_line(line, CUTOFF + 1)) > 0)
        {
                /* We want to check if the line we've just got is longer than CUTOFF */
                if ((len == CUTOFF) && (line[CUTOFF - 1] != '\n')) 
                {
                        /* So the line contains at least CUTOFF characters, and the CUTOFFth character */
                        /* isn't the new-line character.  So we know we want to print the line! */
                        printf("%s", line);
                        print_rest_of_line();
                }
        }
}

/* get_line: read a line into s, return length */
int get_line(char s[],int lim)
{
        int c, i;
        for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
                s[i] = c;
        if (c == '\n') {
                s[i] = c;
                ++i;
        }
        s[i] = '\0';
        return i;
}

/* A function to print the remainder of a line.  If we hit EOF before a new-line */
/* then we print a new-line anyway */
void print_rest_of_line()
{
        int c;
        while (((c = getchar()) != EOF) && (c != '\n'))
                putchar(c);
        putchar('\n'); 
}

