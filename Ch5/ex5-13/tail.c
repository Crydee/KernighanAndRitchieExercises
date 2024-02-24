/* Write the program tail, which prints the last n lines of its input.  By default, n is 10, let us say, but it can be changed by an optional argument,
 * so that
 *     tail -n
 * prints the last n lines.  The program should behave rationally no matter how unreasonable the input or the value of n.  Write the program so it
 * makes best use of available storage; lines should be stored as in the sorting program of Section 5.6, not in a two-dimensional array of fixed size. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1000
#define MAX_NUM_LINES 100
#define LINE_STORE_LEN (MAX_NUM_LINES * MAX_LINE_LEN) + 1

int get_line(char *line, int lim);

int main(int argc, char *argv[])
{
  /* Array we'll use to store the current line of input. */
  char line[MAX_LINE_LEN];
  /* Array we'll use to store up to MAX_NUM_LINES + 1 of input at a time.
   * The additonal 'extra' line is required to guarantee that, assuming
   * enough input lines, we always have stored at least 'MAX_NUM_LINES'
   * of input. */
  char line_store[LINE_STORE_LEN];
  char *pfree = line_store;
  /* Array of pointers to the lines stored in 'line_store'. */
  char *line_ptrs[MAX_NUM_LINES];
  char **pstore = line_ptrs;

  int len;
  /* While there are more lines of input... */
  while ((len = get_line(line, MAX_LINE_LEN))) {
    /* Check if there is room for the line at the end of the array. */
    if (pfree + len >= line_store + LINE_STORE_LEN)
      pfree = line_store;
    strcpy(pfree, line);

    *pstore = pfree;
    /* We need to add len + 1 to pfree as we are actually storing
     * len + 1 chars in the ring buffer as the null-terminator
     * isn't included in the length returned by get_line, and
     * we want 'pfree' to point to the free storage after that. */
    pfree = pfree + len + 1;

    /* Wrap the array of pointers to lines if we have stored
     * a multiple of MAX_NUM_LINES. */
    if (++pstore >= line_ptrs + MAX_NUM_LINES)
      pstore = line_ptrs;
  }

}

/* get_line: Read as much as possible of a line of input into
 * an array of length 'lim' pointed to by 'line'.
 * Return the number of characters stored in line, not counting the
 * null terminator. */
int get_line(char *line, int lim) {
  int c, n;
  for (n = 0 ; (n < lim - 1) && (c = getchar()) != EOF && c != '\n'; n++) {
    /* Store the character in the char pointed to by line, then move line to point
     * to the next char in the array. */
    *line++ = c;
  }
  if (c == '\n') {
    *line++ = c;
    n++;
  }
  *line = '\0';
  return n;
}
