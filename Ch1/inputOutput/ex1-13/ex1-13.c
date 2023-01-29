/* A program to print a histogram of the lengths of words in its input. */
#include <stdio.h>

#define MAXWORDLEN 10

main() {

int lenfreqs[MAXWORDLEN + 1]; /* This array will store the the frequencies with which words of lengths 1, ..., MAXWORDLEN, MAXWORDLEN+ appear */
int c, col, highest_freq, hit_EOF, l, row, wordlen;

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
        wordlen = 0;
    }
    if (c == EOF) {
          hit_EOF = 1;
      }
  }
  else
      ++wordlen;
}

highest_freq = 0;
for(l=0; l<=MAXWORDLEN; ++l) {
  if(lenfreqs[l] > highest_freq)
    highest_freq = lenfreqs[l];
}
printf("The highest frequency is: %d\n", highest_freq);

for( row=0; row<highest_freq; ++row) {
  printf("%3d", highest_freq - row);
  for( col=0; col<MAXWORDLEN + 1; ++col) {
    if( lenfreqs[col] >= (highest_freq - row))
      printf("*");      
    else
      printf(" ");
  }
  printf("\n");
}

for( l=0; l<=MAXWORDLEN; ++l)
    printf(" %d", lenfreqs[l]);

putchar('\n');

}
