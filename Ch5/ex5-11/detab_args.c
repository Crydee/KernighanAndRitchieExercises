/* Mofidy the programs entab and detab to accept a list of tab stops as arguments.
 * Use the default tab settings if there are no arguments. */

#include <stdio.h>
#include <stdlib.h>

#define YES 1
#define NO 0

#define STOPLEN 3 /* The default number of spaces between tab-stops. */
#define  MAXLINE 1000 /* The max length of an input line. */

void detab(char *tab);
void set_tab_arr(int argc, char *argv[], char *);
int tab_pos(char *, int);

int main(int argc, char *argv[]) {
  char tab[MAXLINE + 1];

  set_tab_arr(argc, argv, tab);
  detab(tab);
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

/* detab: replace tab with spaces. */
void detab(char *tab) {
  int c;
  int pos = 1;  /* The next free position in the line. */

  while ((c = getchar()) != EOF) {
    switch (c) {
      case '\t': /* Handle finding a tab character. */
        do {
          putchar(' ');
        } while (tab_pos(tab, pos++) != YES);
        break;
      case '\n': /* Handle newline characters. */
        putchar('\n');
        pos = 1;
        break;
      default: /* Handle any other characters. */
        putchar(c);
        pos++;
        break;
    }
  }
}

/* tab_pos: determine if pos it at a tabstop. */
int tab_pos(char *tab, int pos) {
  if (pos > MAXLINE)
    return YES;
  else
    return tab[pos];
}
