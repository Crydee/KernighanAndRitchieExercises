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

for( l = 0; l <= MAXWORDLEN; ++l) {                     /*Problem: when we pass input with a word longer than MAXWORDLEN, we crash by*/
    lenfreqs[l] = 0;                                    /*trying to increment an elt of the array that doesn't exist.  */
}                                                       
                                                        
while (hit_EOF == 0) {                                  
    c = getchar();
    if ( c == ' ' || c == '\n' || c == '\t') {
        if( wordlen != 0 && wordlen <= MAXWORDLEN){
            ++lenfreqs[wordlen - 1];
            wordlen = 0;
            /*state = OUT;*/}
        else if( wordlen > MAXWORDLEN) {
            ++lenfreqs[MAXWORDLEN];
        }
    }
    else if (c == EOF) {
        if( wordlen != 0 && wordlen <= MAXWORDLEN){
            ++lenfreqs[wordlen - 1];
            wordlen = 0;
            /*state = OUT;*/}
        else if( wordlen > MAXWORDLEN) {
            ++lenfreqs[MAXWORDLEN];
        }
        hit_EOF = 1;
    }
    else {
        ++wordlen;
    }
}
for( l = 0; l <= MAXWORDLEN; ++l)
    printf(" %d", lenfreqs[l]);
}
