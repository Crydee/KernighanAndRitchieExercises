/* Ex 5-16 Add the -d ("directory order") option, which makes comparisons only on letters, numbers,
 * and blanks. Make sure it works in conjunction with -f */
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXLINES 5000     /* max # lines to be sorted */
#define REVERSE 1 /* 00000001 */
#define NUMERIC 2 /* 00000010 */
#define FOLD 4 /* 00000100 */
#define DIR 8 /* 00001000 */

char *lineptr[MAXLINES];  /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int reverse);
void reverse_lines(char *lineptr[], int nlines);
void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);
int charcmp(char *, char *);

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
        default:
          printf("-n for numeric sort, -r to print in reverse order, -f for case-insensitive sort\n");
      }
  if (argc)
    printf("Usage: sort -nrf\n");

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    if (options & NUMERIC)
      qsort((void **) lineptr, 0, nlines - 1, (int (*)(void*, void*)) numcmp);
    else
      qsort((void **) lineptr, 0, nlines - 1, (int (*)(void*, void*))((options & FOLD) ? charcmp: strcmp));
    writelines(lineptr, nlines, options & REVERSE);
    return 0;
  } else {
    printf("input too bit to sort\n");
    return 1;
  }
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
