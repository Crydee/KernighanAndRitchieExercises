#include <stdio.h>

/* fahr_to_cels: convert a temperature in Fahrenheit to a temperature in Celsius */

#define LOWER 0 /* lower limit of temperature table */
#define UPPER 300 /* upper limit of temperature table */
#define STEP 20 /* step size */

float fahr_to_cels(float fahr);

main() {
float fahr;

printf("Fahrenheit\t Celsius\n");

for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) 
  printf("%7.0f\t%10.1f\n", fahr, fahr_to_cels(fahr) );

return 0;
}

float fahr_to_cels(float fahr) {
  return (5.0/9.0) * (fahr - 32.0);
}
