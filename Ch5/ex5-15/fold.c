/* Ex 5-15 Add the option -f to fold upper and lower case together, so that case distinctions are not made during sorting; for example, a and A*/
/* compare equal. */
#include <stdio.h>
#include <string.h>

#define MAXLINES 5000     /* max # lines to be sorted */
#define REVERSE 1
#define NUMERIC 2
char *lineptr[MAXLINES];  /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int reverse);
void reverse_lines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);

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
        default:
          printf("-n for numeric search, -r to print in reverse order\n");
      }
  if (argc)
    printf("Usage: sort -nr\n");

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort((void **) lineptr, 0, nlines - 1, (int (*)(void*, void*))((options & NUMERIC) ? numcmp: strcmp));
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

int mod_strcmp(char *str_one, char *str_two, int case_insensitive) {
  if (!case_insensitive)
    return strcmp(str_one, str_two);

  else {
    /* Go through the strings till we find characters that don't evaluate to equal, or we reach the end of a string. */
    while (*str_one) {
      if (*str_one == *str_two)
        str_one++, str_two++;
      else if ((*str_one == (*str_two + 'A' - 'a')) || (*str_two == (*str_one + 'A' - 'a')))
          str_one++, str_two++;
      else
       break;
    } 
    return *str_one - *str_two;
  }
}
