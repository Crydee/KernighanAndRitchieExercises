/* Write a loop equivalent to the for loop above without using && or ||. */
#include <stdio.h>

#define MAXLINE 1000

main() {

  /* Here's the loop we want to make an equivalent to: */
  /* for (i =0; i<lim - 1 && (c=getchar()) != '\n' && c != EOF; ++i) */
  /*     s[i] = c; */

  /* First version, using while and if */

  int c, i, lim;
  char s[MAXLINE];
  i = 0;

  while (i < lim - 1) {
    if ((c=getchar()) != '\n') {
      if (c != EOF) {
        s[i] = c;
      }
    }
  }

  /* We can write a similar alternative by taking advantage of some of the features of logical and mathematical operators in C. */
  /* "By definition, the numeric value of a relational or logical expression is 1 if the relation is true, and 0 if the */
  /* relation is false" - K & R's C.  Actually, any non-zero value is 'truthy', which means we can use * instead of && */
  /* to join together relational expressions, since 0 times any value is 0, and 0 && any value is also 0. */
  /* The compiler complains about un-sequenced modifications and assignments to c, so I think this is actually quite dodgy! */
  for (i = 0; (i < lim - 1) * ((c = getchar()) != '\n') * (c != EOF); i++)
    s[i] = c;
}

int get_line(char line[], int lim)
{
    int c, ii;

    ii = 0;
    while (ii < lim - 1) {
            if ((c = getchar()) != '\n') {
                    if(c != EOF) {
                        line[ii] = c;
                        ii++;
                    } else {
                            line[ii] = '\0';
                            ii = lim - 1;
                    }
            } else {
                 line[ii] = c;
                 line[ii++] = '\0';
                 ii = lim - 1;
             }
    }
    /* Currently this isn't great as ii is no-longer reliably the length of the line. */
    return ii;
}
