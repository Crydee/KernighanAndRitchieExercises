/* Ex 5-17 Add a field-handling capability, so sorting may be done on fields within lines, each field sorted according to
 * an independens set of options. */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000     /* max # lines to be sorted */
#define REVERSE 1 /* 00000001 */
#define NUMERIC 2 /* 00000010 */
#define FOLD 4 /* 00000100 */
#define DIR 8 /* 00001000 */

char *lineptr[MAXLINES];  /* pointers to text lines */

void read_args(int argc, char *argv[]);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int reverse);
void reverse_lines(char *lineptr[], int nlines);
void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);
int charcmp(char *, char *);
int extended_charcmp(char *, char * , int);
void error(char*);
void substr(char*, char*);

int options = 0;  /* bit encoding of the command line options. */
int pos1 = 0;
int pos2 = 0;

/* sort input lines */
int main(int argc, char *argv[])
{
  int nlines;   /* number of input lines. */
  int options = 0;  /* bit encoding of the command line options. */
  int c;

  while (--argc > 0 && (*++argv)[0] == '-')
    while (c = *++argv[0])
      switch (c) {
        case 'n':
          options |= NUMERIC;
          break;
        case 'r':
          options |= REVERSE;
          break;
        case 'f':
          options |= FOLD;
          break;
        case 'd':
          options |= DIR;
          break;
        default:
          printf("-n for numeric sort, -r to print in reverse order, -f for case-insensitive sort\n");
      }
  if (argc)
    printf("Usage: sort -nrf\n");

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    if (options & NUMERIC)
      qsort((void **) lineptr, 0, nlines - 1, (int (*)(void*, void*)) numcmp);
    else
      qsort((void **) lineptr, 0, nlines - 1, (int (*)(void*, void*))((options & FOLD) ? extended_charcmp: strcmp));
    writelines(lineptr, nlines, options & REVERSE);
    return 0;
  } else {
    printf("input too bit to sort\n");
    return 1;
  }
}

/* read_args: Read in the command line args and set up the global options and positions variables. */
void read_args(int argc, char *argv[]) {
  int c;
  extern int options, pos1, pos2;

  while (--argc > 0 && ((c = (*++argv)[0]) == '-' || c == '+')) {
    if (c == '-' && !isdigit(*(argv[0] + 1)))
      while (c = *++argv[0])
        switch (*argv[0]) {
          case 'n':
            options |= NUMERIC;
            break;
          case 'r':
            options |= REVERSE;
            break;
          case 'f':
            options |= FOLD;
            break;
          case 'd':
            options |= DIR;
            break;
          default:
            printf("sort: illegal option %c\n", *argv[0]);
            error("Usage: sort -dfnr [+pos1] [-pos2]\n");
            break;
        }
    else if (c == '-') {
        pos2 = atoi(++argv[0]);
        if (pos2 < 0)
          error("Invalid, the end position of the match field must be non-negative.\n");
    }
    else if ((pos1 = atoi(++argv[0]) < 0)) {
        printf("The start position must be non-negative.\n");
        error("Usage: sort -dfnr [+pos1] [-pos2]\n");
    }
    else {
      printf("Invalid input: %s\n", argv[0]);
      error("Usage: sort -dfnr [+pos1] [-pos2]\n");
    }
  }
  if (argc || pos1 > pos2)
    error("Usage: sort -dfnr [+pos1] [-pos2]\n");
}

/* writelines: write out nlines lies pointed to by the ptrs in lineptr. */
void writelines(char *lineptr[], int nlines, int reverse) {
  int i;

  /* Print in decreasing order. */
  if (reverse)
    for (i = nlines-1; i >= 0; i--)
      printf("%s", lineptr[i]);
  /* Print in increasing order. */
  else
    for (i = 0; i < nlines; i++)
      printf("%s", lineptr[i]);
}

/* charcmp: case-insensitive comparison of two strings. */
int charcmp(char *str_one, char *str_two) {
  for (; tolower(*str_one) == tolower(*str_two); str_one++, str_two++) {
    if (!*str_one)
      /* The two strings evaluate equal. */
      break;
  }
  return *str_one - *str_two;
}

/* An extended charcmp that can handle both case-insensitive comparison, as well as "directory order" comparison. */
int extended_charcmp(char *str_one, char *str_two, int options) {
  char a, b;

  do {

    /* We are only comparing letters, numbers, and blanks, so skip any other characters. */
    if (options & DIR) {
      while (!isalnum(*str_one) && !isblank(*str_one) && *str_one)
        str_one++;

      while (!isalnum(*str_two) && !isblank(*str_two) && *str_two)
        str_two++;
    }

    /* Compare, using the method specified in options. */
    a = (options & FOLD) ? tolower(*str_one) : *str_one;
    b = (options & FOLD) ? tolower(*str_two) : *str_two;

    /* Check to see if the strings are exactly equal, to make sure we don't fall off the end! */
    if ((a == b) && (*str_one == '\0'))
      return 0;

    str_one++;
    str_two++;
  } while (a == b);

  return a - b;
}

/* error: Print an error message and then exit. */
void error(char *err_str) {
  printf("%s", err_str);
  exit(1);
}

/* substr: Get a substring of s and put in str. */
void substr(char* s, char* str) {
  extern int pos1, pos2;
  int i, j, len = strlen(s);

  if (pos2 > 0 && len > pos2)
    len = pos2;

  for (i = 0, j = pos1; j < len; i++, j++)
    str[i] = s[j];
  str[++i] = '\0';
}
