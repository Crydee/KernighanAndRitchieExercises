/* Ex 5-15 Add the option -f to fold upper and lower case together, so that case distinctions are not made during sorting; for example, a and A*/
/* compare equal. */
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXLINES 5000     /* max # lines to be sorted */
#define REVERSE 1 /* 00000001 */
#define NUMERIC 2 /* 00000010 */
#define FOLD 4 /* 00000100 */

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
      /* The two strings evalueate equal. */
      break;
  }
  return *str_one - *str_two;
}
