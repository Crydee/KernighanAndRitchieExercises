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

/* Reverse an array of characters */
void reverses(char s[]) {
  int swp, idx, last_idx;

  last_idx = 0;
  while(s[last_idx] != '\0')
          ++last_idx;
  --last_idx; /* At this point, last_idx is the index of the character before the first '\0' in the input array */


  for( idx = 0; idx < last_idx - idx; ++idx) {
    swp = s[idx];
    s[idx] = s[last_idx - idx];
    s[last_idx - idx] = swp;
  }
}
