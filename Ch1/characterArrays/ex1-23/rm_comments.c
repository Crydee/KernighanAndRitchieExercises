/* Write a program to remove all comments from a C program.  Don't forget to handle quoted strings and character */
/*   constants properly.  C comments do not nest. */

#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define LINE_LENGTH 1000 /* The max # of characters we can deal with in a line. */

int get_line(char line[], int lim);
int remove_comments(char input_line[], char output_line[], int lim);

int main()
{
        int c;
        char line[LINE_LENGTH], line_without_comments[LINE_LENGTH];

        while ((c = get_line(line, LINE_LENGTH)) != 0)
        {
                remove_comments(line, line_without_comments, LINE_LENGTH);
                printf("%s", line_without_comments);
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

/* Take a line stored in an array and copy up to (lim - 1) elts of the contents of that line, minus any comments, into another array. */
int remove_comments(char input_line[], char output_line[], int lim)
{
        int c, ii, io, in_string, in_char_const, in_comment;

        c = io = in_string = in_char_const = in_comment = 0;

        for (ii = 0; (io < lim - 1) && ((c = input_line[ii]) != '\0'); ii++)
        {
                if (in_comment == FALSE)
                {
                        if (in_string == TRUE)
                        {
                                if (c == '"')
                                        in_string = FALSE;
                                output_line[io] = c;
                                io++;
                        }
                        else if (in_char_const == TRUE)
                        {
                                if (c == '\'')
                                        in_char_const = FALSE;
                                output_line[io] = c;
                                io++;
                        }

                        else if ((c == '/') && (((c = input_line[ii + 1]) == '*')))
                        {
                                in_comment = TRUE;
                                ii++;
                                /* We want to increment the index as we don't care what we find in the comment, we aren't going to copy it, and if ii + 2'th */
                                /* character is a / then we'll end up confused if we start looking for the corresponding end of comment sequence immediately */
                                /* i.e. the seq /<star>/. */
                        }
                        else
                        {
                                if (c == '"')
                                        in_string = TRUE;
                                else if (c == '\'')
                                        in_char_const = TRUE;
                                output_line[io] = c;
                                io++;
                        }
                }
                else
                {
                        if ((input_line[ii] == '*') && (input_line[ii + 1] == '/'))
                        {
                                ii++;
                                in_comment = FALSE;
                        }
                }
        }
        output_line[io] = '\0';

        return io;
}        
