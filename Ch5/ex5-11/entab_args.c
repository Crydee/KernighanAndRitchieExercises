/* Modify the programs entab and detab to accept a list of tab stops as arguments.
 * Use the default tab settings if there are no arguments. */
#include <stdio.h>
#include <stdlib.h>

#define YES 1
#define NO 0

#define STOPLEN 8 /* The # of spaces between tab-stops. */
#define MAXLINE 1000 /* The max length of an input line. */

void entab(char *);
void set_tab_arr(int argc, char *argv[], char *);
int tab_pos(char *, int);

int main(int argc, char *argv[]) {
  char tab[MAXLINE + 1];

  set_tab_arr(argc, argv, tab);
  entab(tab);
}

void entab(char *tab) {
  int c, pos; /* pos is the position of the space in the output line that the program is at. */
  int nb = 0; /* The number of blanks we need to print. */
  int nt = 0; /* The number of tabs we need to print. */

  for (pos = 1; (c = getchar()) != EOF; pos++) {
    if (c == ' ') {
      /* Check to see if the space character has taken us to a tabstop and, if so, replace the accumulated spaces with a tab. */
      if (!tab_pos(tab, pos)) {
        nb++;
      }
      else {
        nb = 0;
        nt++;
      }
    } else {

      for (; nt > 0; nt--) {
        putchar('\t'); /* Print the accumulated tabs. */
      }
      if (c == '\t') {
        nb = 0; /* Forget the accumulated blanks. */
        while (!tab_pos(tab, ++pos))
          ;
      } else if (c == '\n') {
        pos = 0; /* This will be incremented back to 1 at the end of this iteration. */
      }

      for (; nb > 0; nb--)
        putchar(' '); /* Print the accumulated blanks. */
      putchar(c);
    }
  }
}

/* set_tab_arr: set the contents of the tabstop array from a list provided when the program was invoked. */
void set_tab_arr(int argc, char *argv[], char *tab) {
  for (int i = 0;i <= MAXLINE; i++)
    tab[i] = NO;

  /* See if we have been provided with a list of tab stops. */
  if (argc > 1) {
    while (--argc) {
      int tabstop = atoi(*++argv);
      if (0 < tabstop && tabstop <= MAXLINE) {
        tab[tabstop] = YES;
      }
    }
  } else {/* Use default tab stops. */
    for (int i = 1; i <= MAXLINE; i++)
      if ((i % STOPLEN) == 0)
        tab[i] = YES;
  }
}

/* tab_pos: determine if pos is at a tabstop. */
int tab_pos(char *tab, int pos) {
  if (pos > MAXLINE)
    return YES;
  else
    return tab[pos];
}
