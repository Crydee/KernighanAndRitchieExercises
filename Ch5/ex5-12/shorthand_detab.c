/* Extend entab and detab to accept the shorthand
 *     entab -m +n
 * to mean tab stops every n columns, starting at column m.  Choose convenient (for the user) default behaviour. */

#include <ctype.h>
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
  int tab_interval = 0, tab_start = 0;

  for (int i = 0;i <= MAXLINE; i++)
    tab[i] = NO;

  /* See if we have been provided with any arguments. */
  if (argc > 1) {
    while (--argc) {
      if (isdigit((*++argv)[0])) { /* If the 1'st char of the arg is a digit then treat the arg as a tabstop. */
        int tabstop = atoi(*argv);
        if (0 < tabstop && tabstop <= MAXLINE)
          tab[tabstop] = YES;
      } else if (*argv[0] == '+') { /* the +n case. */
        tab_interval = atoi(++(*argv));
        printf("Setting tabstops every %d columns\n", tab_interval);
      } else if (*argv[0] == '-') { /* the -m case. */
        tab_start = atoi(++(*argv));
        printf("Setting tabstops starting from column %d\n", tab_start);
      }
    }
    /* Set default values if the user doesn't specify any. */
    tab_start = tab_start > 0 ? tab_start : STOPLEN;
    tab_interval = tab_interval > 0 ? tab_interval : STOPLEN;

    tab[tab_start] = YES;
    for (int i = tab_start + 1; i <=MAXLINE; i++) {
      if (((i - tab_start) % tab_interval) == 0)
        tab[i] = YES;
    }
  } else {/* Use default tab stops. */
      for (int i = 1; i <= MAXLINE; i++) {
        if ((i % STOPLEN) == 0) {
          tab[i] = YES;
      }
    }
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

/* tab_pos: determine if pos is at a tabstop. */
int tab_pos(char *tab, int pos) {
  if (pos > MAXLINE)
    return YES;
  else
    return tab[pos];
}
