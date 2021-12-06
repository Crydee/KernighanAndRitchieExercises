#include <stdio.h>

main() {

int c, col, i, max_freq, row;
int char_freq_arr[78];

for (i=0; i < 78; i++) {
  char_freq_arr[i] = 0;
}
max_freq = 0;

while ((c = getchar()) != EOF) {
  if ((48 <= c) && (c <= 126)) {
    ++char_freq_arr[c - 48];
    if (char_freq_arr[c - 48] > max_freq)
      max_freq = char_freq_arr[c - 48];
    }
  }

/*for (i = 0; i < 78; i++) {
  printf("%d", char_freq_arr[i]);  
}*/




/*printf("The value of 'c' is %d and the value of d is %d\n", 'c', 'd');*/

for( row=0; row<max_freq; ++row) {
  printf("%3d", max_freq - row);
  for( col=0; col<78; ++col) {
    if( char_freq_arr[col] >= (max_freq - row))
      printf("*");      
    else
      printf(" ");
  }
  printf("\n");
}
printf("  ");
for (i = 48; i < 127; i++) {
  printf("%c", i);
  }
printf("\n");
}
