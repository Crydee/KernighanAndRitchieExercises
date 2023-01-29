/* A program to check a C program for rudimentary syntax errors like unbalanced parentheses, brackets and braces.  Don't forget about */
/* quotes, both single and double, escape sequences, and comments. */

#include <stdio.h>

#define LINE_LEN 1000 /* The max length of line we'll deal with (+1 to leave space for null char). */
#define TRUE 1
#define FALSE 0
int get_line(char line[], int lim);
int remove_comments(char input_line[], char output_line[], int lim);

int main()
{
        char line[LINE_LEN], line_without_comments[LINE_LEN];
        int in_string, in_char_const, in_escape_seq, paren_count, bracket_count, brace_count;

        int ii, c;
        /* We get a line, and keep getting lines until get_line returns 0, indicating there is no more input. */

        bracket_count = brace_count = paren_count = 0;
        in_string = in_char_const = in_escape_seq = FALSE;

        while (get_line(line, LINE_LEN) != 0)
        {
                /* Now, the arr line contains the contents of the current line of input.  We first remove all comments, as they are irrelevant to the syntax of the code, then iterate through, counting the chars we are concerned with. */
                remove_comments(line, line_without_comments, LINE_LEN);
                for (ii = 0; (c = line_without_comments[ii]) != '\0'; ii++)
                {
                        if (in_escape_seq == TRUE)
                        {
                                in_escape_seq = FALSE;
                        }
                        else if (in_string == TRUE)
                        {
                                if (c == '\\')
                                        in_escape_seq = TRUE;
                                /* If we're in a string, then we don't want to count braces and the like, we just want to know when we've left the string. */
                                else if (c == '"')
                                        in_string = FALSE;
                        }
                        else if (in_char_const == TRUE)
                        {
                                if (c == '\\')
                                        in_escape_seq = TRUE;
                                /* If we're in a single-quoted string, then we don't want to count braces and the like, we just want to know when we've left the string. */
                                else if (c == '\'')
                                        in_char_const = FALSE;
                        }
                        else
                        {
                                if (c == '"')
                                        in_string = TRUE;
                                else if (c == '\'')
                                        in_char_const = TRUE;
                                else if (c == '\\')
                                        in_escape_seq = TRUE;
                                else if (c == '(')
                                        paren_count++;
                                else if (c == ')')
                                        paren_count--;
                                else if (c == '[')
                                        bracket_count++;
                                else if (c == ']')
                                        bracket_count--;
                                else if (c == '{')
                                        brace_count++;
                                else if (c == '}')
                                        brace_count--;

                        }
                }
        }

        if ((in_char_const == FALSE) && (in_string == FALSE) && (paren_count == 0) && (bracket_count == 0) && (brace_count == 0))
                printf("No un-balanced brackets, braces, or parens, and no un-closed strings (single or double quoted)\n");
        else
        {
                printf("Error, the C file contains a syntax error\n");
                if (in_char_const == TRUE)
                        printf("There is a single-quoted string that is not closed\n");
                if (in_string == TRUE)
                        printf("There is a string that is not closed\n");
                if (paren_count != 0)
                        printf("There is an unbalanced number of parentheses, with a net %d parentheses\n", paren_count);
                if (bracket_count != 0)
                        printf("There is an unbalanced number of brackets, with a net %d brackets\n", bracket_count);
                if (brace_count != 0)
                        printf("There is an unbalanced number of braces, with a net %d braces\n", brace_count);

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

