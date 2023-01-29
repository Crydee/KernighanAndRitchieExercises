/* ex1-19 Write a fct reverse(s) that reverses the char string s.  Use it to write a program that reverses its input a line at a time */

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int maxline);
void reverses(char s[]);

int main() {
 
        char s[MAXLINE]; 
        while(get_line(s, MAXLINE) !=0) {
          reverses(s);
          printf("%s", s);
        }
        printf("\n"); /* Print a space once the program has finished */
        
}

/* get_line: read a line into s, return length */
int get_line(char s[],int lim)
{
        int c, i;
        for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
                s[i] = c;
        if (c == '\n') {
                s[i] = c;
                ++i;
        }
        s[i] = '\0';
        return i;
}

/* Reverse a null-terminated array of characters */
void reverses(char s[]) {
  int swp, idx, last_idx;

  last_idx = 0;
  while(s[last_idx] != '\0')
          ++last_idx;
  --last_idx; /* At this point, last_idx is the index of the character before the first '\0' in the input array */

        /* Now that we know the index of the final element (let's say n) in the array, we want to swap the elements */
        /* in turn, swapping the k'th elt (index k-1) with the n-k'th elt (index (n-1)-k).  We take advantage of the*/
        /* fact that integer division in C truncates in the for loop's condition.*/
  for( idx = 0; idx < ((last_idx + 1) / 2); ++idx) {
    swp = s[idx];
    s[idx] = s[last_idx - idx];
    s[last_idx - idx] = swp;
  }
  /* The function returns no value as the array that is passed as*/
  /* an argument is directly mutated as a consequence of the fact*/
  /* that in C arrays are passed as args. by reference, not by*/
  /* value. */
}
