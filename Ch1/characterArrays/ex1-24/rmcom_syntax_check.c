


#include <stdio.h>

#define LINE_LEN 1000 
#define TRUE 1
#define FALSE 0
int get_line(char line[], int lim);
int remove_comments(char input_line[], char output_line[], int lim);

int main()
{
        char line[LINE_LEN], line_without_comments[LINE_LEN];
        int in_string, in_char_const, in_escape_seq, paren_count, bracket_count, brace_count;

        int ii, c;
        

        bracket_count = brace_count = paren_count = 0;
        in_string = in_char_const = in_escape_seq = FALSE;

        while (get_line(line, LINE_LEN) != 0)
        {
                
                remove_comments(line, line_without_comments, LINE_LEN);
                for (ii = 0; (c = line_without_comments[ii]) != '\0'; ii++)
                {
                        if (in_escape_seq == TRUE)
                        {
                                in_escape_seq = FALSE;
                        }
                        else if (in_string == TRUE)
                        {
                                
                                if (c == '"')
                                        in_string = FALSE;
                        }
                        else if (in_char_const == TRUE)
                        {
                                
                                if (c == '\'')
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

