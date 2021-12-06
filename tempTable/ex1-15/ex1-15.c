#include <stdio.h>

/* fahr_to_cels: convert a temperature in Fahrenheit to a temperature in Celsius */

float fahr_to_cels(float fahr);

main() {
float fahr;

#define LOWER 0 /* lower limit of temperature table */
#define UPPER 300 /* upper limit of temperature table */
#define STEP 20 /* step size */

printf("Fahrenheit\t Celsius\n");

for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
  printf("%7.0f\t%10.1f\n", fahr, fahr_to_cels(fahr) );
}
}

float fahr_to_cels(float fahr) {
  return 5 * (fahr - 32) / 9;
}
