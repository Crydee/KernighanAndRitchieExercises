#include <stdio.h>

main() {

int c;
int prevcharspace = 0;

while ((c = getchar()) != EOF) {
	
	if (c == ' ') {
		if (prevcharspace == 0) {
		putchar(c);
		prevcharspace = 1;
		}
	}
	if ( c != ' ') {
		putchar(c);
		prevcharspace = 0;
	}
}
}
