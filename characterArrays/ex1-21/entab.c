/* Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. */
/* Use the same tab stops as for detab. */

#include <stdio.h>

#define STOPLEN 10 /* The # of spaces between tab-stops. */

void null_arr(char arr[], int length);

int main()
{
  int c;
  int num_cons_blanks; /* The number of consecutive blanks that we have encountered since last printing a char. */
  int position_mod_tab; /* Position of the last printed char in the current line, past the last tab-space. */
  char blanks[STOPLEN + 1]; /* Array to store the blanks that we encounter, null terminated.*/

  num_cons_blanks = position_mod_tab = 0;

  while ((c = getchar()) != EOF)
  {
    if (c == " ")
    {
        blanks[num_cons_blanks] = c;
        num_cons_blanks++;
        if (num_cons_blanks == (STOPLEN - position_mod_tab))
        {
            /* The blanks in our array would take us to the next tab-stop, so print out a tab. */
            printf("\t");
            /* Zero our position relative to the last tab stop, the idx of the arr, and the arr's contents. */
            null_arr(blanks, num_cons_blanks + 1);
            position_mod_tab = num_cons_blanks = 0;
        }
    }
    else 
    {
        /*Print out any blanks that we may have and then print out the character, whilst keeping track of position_mod_tab.  Zero the idx of the arr and it's elts (if spaces printed)*/
    }
  }
}

void null_arr(char arr[], int length)
{
    int idx;
    
    for (idx = 0; idx < length; idx++)
      arr[idx] = '\0';
}