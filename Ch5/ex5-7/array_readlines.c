/* Rewrite readlines to store lines in an array supplied by main, rather than calling alloc to maintain storage.  How much faster is the
 * program? */

#include <stdio.h>
#include <string.h>
#define MAXLEN 1000 /* Max length of any input line. */
#define ALLOCSIZE 10000 /* Size of available space. */

void afree(char *p);
char *alloc(int n);
int modified_readlines(char *lineptr[], int maxlines, char *parr, int arrlen);
int ptr_getline(char *s, int lim);
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);

int main() {
  char mains_arr[ALLOCSIZE], *lines[10];

  printf("Calling readlines\n");
  readlines(lines, 10);

  printf("Calling our modified readlines\n");
  modified_readlines(lines, 10, mains_arr, ALLOCSIZE);
}

/* ptr_getline: get line into s, return length. */
int ptr_getline(char *s, int lim) {
  int c;
  char * start = s;

  while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
    *s++ = c; /* Make sure this correctly increments s and doesn't increment the character that s points to. */
  if (c == '\n')
    *s++ = c;
  *s = '\0';
  return s - start;
}

/* modified_readlines: read input line.  Main passes in a pointer to the arr it provides as parr. */
int modified_readlines(char *lineptr[], int maxlines, char *parr, int arrlen) {
  int len, nlines;
  char line[MAXLEN], *pstart = parr;

  nlines = 0;
  while ((len = ptr_getline(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (parr + len >= pstart + arrlen))
      return -1;
    else {
      line[len-1] = '\0'; /* Delete newline. */
      strcpy(parr,line);
      lineptr[nlines++] = parr;
      parr += len;
    }
  return nlines;
}

/* readlines: read input line. */
int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = ptr_getline(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len-1] = '\0'; /* Delete newline. */
      strcpy(p,line);
      lineptr[nlines++] = p;
    }
  return nlines;
}

/* writelines: write output lines. */
void writelines(char *lineptr[], int nlines) {
  int i;

  for (i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
}

static char allocbuf[ALLOCSIZE]; /* Storage for alloc. */
static char *allocp = allocbuf; /* Next free posistion. */

/* alloc: return pointer to n characters. */
char *alloc(int n) {
  if (allocbuf + ALLOCSIZE - allocp >= n) { /* It fits. */
    allocp += n;
    return allocp - n; /* Old pointer. */
  } else /* Not enough room. */
    return 0;
}

/* afree: free storage pointed to by p. */
void afree(char *p) {
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}
