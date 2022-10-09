/* Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. */
/* Use the same tab stops as for detab. */

#include <stdio.h>

#define STOPLEN 10 /* The # of spaces between tab-stops. */

void null_arr(char arr[], int length);

int main()
{
  int c;
  int num_cons_blanks; /* The number of consecutive blanks that we have encountered since last printing a char. */
  int position_mod_tab; /* Position, past the last tab-stop of the next character to be printed in the line. */
  char blanks[STOPLEN + 1]; /* Array to store the blanks that we encounter, null terminated.*/

  num_cons_blanks = position_mod_tab = 0;
  null_arr(blanks, STOPLEN + 1);

  while ((c = getchar()) != EOF)
  {
    if (c == ' ')
    {
        blanks[num_cons_blanks] = c;
        num_cons_blanks++;
        if (num_cons_blanks == (STOPLEN - position_mod_tab))
        {
            /* The blanks in our array would take us to the next tab-stop, so print out a tab. */
            printf("\t");
            /* Zero our position relative to the last tab stop, the idx of the arr, and the arr's contents. */
            null_arr(blanks, num_cons_blanks);
            position_mod_tab = num_cons_blanks = 0;
        }
    }
    else 
    {
        /* We print out the preceding blanks and then the non-blank char. */
        if (num_cons_blanks != 0)
        {
          /* Print out the preceding blanks. */
          printf("%s", blanks);
          position_mod_tab = ((position_mod_tab + num_cons_blanks) % STOPLEN);
          null_arr(blanks, num_cons_blanks);
          num_cons_blanks = 0;
        }
        
        printf("%c", c);
        if ((c == '\n') || (c == '\t'))
        {
          position_mod_tab = 0;
        }
        else
        {
          position_mod_tab = ((position_mod_tab + 1) % STOPLEN);
        }        
    }
  }
}

void null_arr(char arr[], int length)
{
    int idx;
    
    for (idx = 0; idx < length; idx++)
      arr[idx] = '\0';
}