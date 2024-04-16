/* Ex 5-14 Modify the sort program to handle a -r flag, which indicates sorting in reverse (decreasing) order.  Be sure that -r works with -n. */
#include <stdio.h>
#include <string.h>

#define MAXLINES 5000     /* max # lines to be sorted */
char *lineptr[MAXLINES];  /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void reverse_lines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);

/* sort input lines */
int main(int argc, char *argv[]) 
{
  int nlines;   /* number of input lines. */
  int numeric = 0;    /* 1 if numeric sort */
  int reverse = 0;    /* 1 if print in reverse */
  int c;

  while (--argc > 0 && (*++argv)[0] == '-')
    while (c = *++argv[0])
      switch (c) {
        case 'n':
          numeric = 1;
          break;
        case 'r':
          reverse = 1;
          break;
        default:
          printf("-n for numeric search, -r to print in reverse order\n");
      }

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort((void **) lineptr, 0, nlines - 1, (int (*)(void*, void*))(numeric ? numcmp: strcmp));
    if (reverse)
      reverse_lines(lineptr, nlines);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("input too bit to sort\n");
    return 1;
  }
}
