/* A program to print a histogram of the lengths of words in its input. */
#include <stdio.h>

#define INWORD 1
#define PREVCHARWSPACE 0
#define MAXWORDLEN 10

main() {

int lenfreqs[MAXWORDLEN + 1]; /* This array will store the the frequencies with which words of lengths 1, ..., MAXWORDLEN, MAXWORDLEN+ appear */
int c, hit_EOF, l, /*state*/ wordlen;

hit_EOF = 0;
/*state = OUT;*/
wordlen = 0;

for( l = 0; l <= MAXWORDLEN; ++l) {
    lenfreqs[l] = 0;
}

while (hit_EOF == 0) {
    c = getchar();
    if ( c == ' ' || c == '\n' || c == '\t') {
        if( wordlen != 0){
            ++lenfreqs[wordlen - 1];
            wordlen = 0;
            /*state = OUT;*/}
    }
    else if (c == EOF) {
        if( wordlen != 0){
            ++lenfreqs[wordlen - 1];
            wordlen = 0;
            /*state = OUT;*/}
        hit_EOF = 1;
    }
    else {
        ++wordlen;
    }
}
for( l = 0; l <= MAXWORDLEN; ++l)
    printf(" %d", lenfreqs[l]);
}
