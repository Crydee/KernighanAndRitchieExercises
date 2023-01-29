#include <stdio.h>

#define PRINTABLE 81 /* We'll print lines containing at least this many characters, including a final newline character */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* A program to print all input lines that contain at least PRINTABLE characters */ 
main() {
        char line[PRINTABLE + 1]; /* stores up to the first PRINTABLE chars of the current input line, null-terminated */
        int len/* the length of current the input line */, x;

        while ((len = get_line(line, PRINTABLE + 1)) > 0) {
                /* The while condition is false when we have iterated through every line in the input */
                if (len == PRINTABLE) {
                        /* The current line has at least PRINTABLE characters.  We want to print the section of the line that we stored
                         * in line and then the rest of the input line */
                        printf("%s", line);


                        /*if (line[PRINTABLE] == '\0')
                          printf("The last elt of the array is '\\0' \n");*/

                        if (line[PRINTABLE - 1] != '\n') {
                                /* In this case, the line is strictly longer than 81 characters */
                                /*printf("The line is longer than 81 chars\n");*/
                                while (((x = getchar()) != EOF) && (x != '\n')) {
                                        printf("%c", x);
                                }
                                if (x == '\n')
                                        printf("\n");
                        }
                        /*printf("\n");*/
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
        int i;
        i = 0;
        while ((to[i] = from[i]) != '\0')
                ++i;
}
