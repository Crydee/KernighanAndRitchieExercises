/* Extend entab and detab to accept the shorthand
 *     entab -m +n
 * to mean tab stops every n columns, starting at column m.  Choose convenient (for the user) default behaviour. */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define YES 1
#define NO 0

#define STOPLEN 8 /* The default number of spaces between tab-stops. */
#define  MAXLINE 50 /* The max length of an input line. */

void display_output_buffer(char *);
void display_tabarr(char *);
void entab(char *);
void set_tab_arr(int argc, char *argv[], char *);
int tab_pos(char *, int);

char out_buf[MAXLINE + 1];

int main(int argc, char *argv[]) {
  char tab[MAXLINE + 1];

  set_tab_arr(argc, argv, tab);
  display_tabarr(tab);
  entab(tab);
  printf("outbuf is \n%s\n", out_buf);
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

void push(int, char *);
void display_output_buffer(char *);

void entab(char *tab) {
  int c, pos; /* pos is the position of the space in the output line that the program is at. */
  int nb = 0; /* The number of blanks we need to print. */
  int nt = 0; /* The number of tabs we need to print. */

  for (pos = 1; (c = getchar()) != 'X'; pos++) {
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
        push('\t', out_buf); /* Print the accumulated tabs. */
      }
      if (c == '\t') {
        nb = 0; /* Forget the accumulated blanks. */
        while (!tab_pos(tab, ++pos))
          ;
      } else if (c == '\n') {
        pos = 0; /* This will be incremented back to 1 at the end of this iteration. */
      }

      for (; nb > 0; nb--)
        push(' ', out_buf); /* Print the accumulated blanks. */
      push(c, out_buf);
    }
  }
  display_output_buffer(out_buf);
}

/* tab_pos: determine if pos is at a tabstop. */
int tab_pos(char *tab, int pos) {
  if (pos > MAXLINE)
    return YES;
  else
    return tab[pos];
}

void display_tabarr(char * tab) {
  for (int i = 0; i <= MAXLINE + 1; i++)
    printf("%c", tab[i] ? 'Y' : 'N');
  printf("\n");
}

void push(int c, char *buf) {
  static int i = 0;
  if (i < MAXLINE + 1) {
    buf[i] = c;
    buf[++i] = '\0';
  } else
  printf("output buffer is full\n");
}

void display_output_buffer(char *out_buf) {
  for (int i = 0; i <= MAXLINE + 1; i++) {
    if (isalnum(out_buf[i]))
      printf("%c", out_buf[i]);
    else {
      switch (out_buf[i]) {
        case '\t':
          printf("T");
          break;
        case ' ':
          printf("S");
          break;
        default:
          printf("%c", out_buf[i]);
          break;
      }
    }
  }
}
