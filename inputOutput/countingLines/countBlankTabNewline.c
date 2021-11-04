#include <stdio.h>

main() {

	int nb, nt, nl;
	int c;
	
	nb = 0;
	nt = 0;
	nl = 0;
	while( (c = getchar()) != EOF ) {
		if(c == ' ')
			++nb;
		else if(c == '\t')
			++nt;
		else if(c == '\n')
			++nl;
	}
	printf("The number of blanks is: %d\n", nb);
	printf("The number of tabs is: %d\n", nt);
	printf("The number of newlines is: %d\n", nl);

}

