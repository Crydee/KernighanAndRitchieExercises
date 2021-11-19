/* A program to print a histogram of the lengths of words in its input. */
#include <stdio.h>

#define MAXWORDLEN 10

main() {

int lenfreqs[MAXWORDLEN + 1]; /* This array will store the the frequencies with which words of lengths 1, ..., MAXWORDLEN, MAXWORDLEN+ appear */
int c, hit_EOF, l, wordlen;

hit_EOF = 0;
wordlen = 0;

for( l = 0; l <= MAXWORDLEN; ++l) {
    lenfreqs[l] = 0;
}

while (hit_EOF == 0) {
  c = getchar();
  if ((c == ' ') || (c == '\n') || (c == '\t') || (c == EOF)) {
    if((wordlen != 0) && (wordlen <= MAXWORDLEN)){
          ++lenfreqs[wordlen - 1];
          wordlen = 0;
          }
    else if((wordlen != 0) && (wordlen >= MAXWORDLEN)) {
        ++lenfreqs[MAXWORDLEN];
    }
    if (c == EOF) {
          hit_EOF = 1;
      }
  }
  else
      ++wordlen;
}
for( l = 0; l <= MAXWORDLEN; ++l)
    printf(" %d", lenfreqs[l]);
    putchar('\n');
}
