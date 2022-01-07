#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print the length of arbitrarily long input lines, and as much as possible of the text */
main()
{
        char line[MAXLINE]; /* current input line */
        int len/* the length of the input line */, x;

        len = get_line(line, MAXLINE);

        if ((len == (MAXLINE - 1)) && (line[MAXLINE - 2]) != '\n') {
                /* This is the case when the first MAXLINE - 1 elts of line
                 * have all not been '\n' or EOF. */
                printf("The contents of the line are too long to entirely print.  The abridged contents are: ");

                while (((x = getchar()) != EOF) && (x != '\n'))
                        ++len;

                if (x == '\n')
                        ++len;

                /* print the contents of line up to the '\0' added by get_line */
                for (x = 0; x < (MAXLINE - 2); ++x) {
                        printf("%c", line[x]);
                }
                printf("\n");

        }
        else {

                printf("The line's contents: ");
                for (x = 0; x < len; ++x) {
                        printf("%c", line[x]);
                }
        }
        printf("The length of the line is: %d characters long\n", len);

        return 0;
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
        int i;
        i = 0;
        while ((to[i] = from[i]) != '\0')
                ++i;
}
