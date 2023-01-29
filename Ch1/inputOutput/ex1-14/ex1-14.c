#include <stdio.h>
/* print a histogram of the frequencies of different characters in input. */

/* We assume that the values of all of the visible characters are a consecutive sequence of increasing */
/* positive integers between the value for the character of ! and the value for the character of ~ */
main() {

int c, col, i, max_freq, num_vis_chars, row;
num_vis_chars = ('~' - '!') + 1;
printf("the val of num_vis_chars: %d\n", num_vis_chars);
int char_freq_arr[num_vis_chars];

for (i=0; i < num_vis_chars; i++) {
  char_freq_arr[i] = 0;
}
max_freq = 0;

while ((c = getchar()) != EOF) {
  if (('!' <= c) && (c <= '~')) {
    ++char_freq_arr[c - '!'];
    if (char_freq_arr[c - '!'] > max_freq)
      max_freq = char_freq_arr[c - '!'];
    }
  }

for (row = 0; row < max_freq; ++row) {
  printf("%3d", max_freq - row);
  for (col = 0; col < num_vis_chars; ++col) {
    if (char_freq_arr[col] >= (max_freq - row))
      printf("*");      
    else
      printf(" ");
  }
  printf("\n");
}
printf("   "); /* Three spaces so that the horizontal axis aligns with the histogram */
for (i = '!'; i <= '~'; i++) {
  printf("%c", i);
  }
printf("\n");
}
