/* Modify the programs entab and detab to accept a list of tab stops as arguments.
 * Use the default tab settings if there are no arguments. */
#include <stdio.h>

#define STOPLEN 10 /* The # of spaces between tab-stops. */

void detab(int argc, char *argv[]);
void null_arr(char arr[], int length);

int main() {}

void detab(int argc, char *argv[]) {
  int c, pos = 1; /* pos is the position of the space in the output line that the program is at. */
  int nb = 0; /* The number of blanks we need to print. */
  int nt = 0; /* The number of tabs we need to print. */

  for (pos = 1; (c = getchar()) != EOF; pos++) {
    if (c == ' ') {

      /* Check to see if the space character has taken us to a tabstop and, if so, replace the accumulated spaces with a tab. */
      if ((pos % STOPLEN) != 0) {
        nb++;
      }
      else {
        nb = 0;
        nt++;
      }

    } else {

      while (nt--)
        putchar('\t'); /* Print the accumulated tabs. */

      if (c == '\t') {
        nb = 0; /* Forget the accumulated blanks. */
        pos += ((pos - 1) % STOPLEN) - 1; /* Move pos to the next tab stop.  pos will be incremented again at the end of this iteration. */
      } else if (c == '\n') {
        pos = 0; /* This will be incremented back to 1 at the end of this iteration. */
      }

      while (nb--)
        putchar(' '); /* Print the accumulated blanks. */
      putchar(c);
    }
  }
}
