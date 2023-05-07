/* Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside).  write a version */
/* with only one test inside the loop and measure the difference in run-time. */

#include <stdio.h>

int binsearch(int x, int v[], int n);
int mod_binsearch(int x, int v[], int n);

main() {
  int ii, test_arr[] = {0,1,2,3,3,4,5,6,7,8,9}, small_arr[] = {0,1,2};

  printf("the test array is: ");

  for (ii = 0; ii < 11; ii++)
    printf("%d%c ", test_arr[ii], ii == 9? ' ': ',');
  printf("\n");

  for (ii = 0; ii < 10; ii++) {
    printf("The index of the value %d is %d\n", ii, mod_binsearch(ii, test_arr, 11));
  }

  for (ii = 0; ii < 3; ii++)
    printf("The index of the value %d is %d\n", ii, mod_binsearch(ii, small_arr, 3));

}

/* find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low+high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else if (x > v[mid])
      low = mid + 1;
    else /* found a match */ 
      return mid;
  }
  return -1; /* no match */
}

int mod_binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = -1;
  high = n;
  while (low + 2 < high) {
    mid = (low+high) / 2;
    printf("set mid to %d\n", mid);
    if (x > v[mid]) {
      low = mid;
      printf("setting low to %d\n", low);
    }
    else {
      high = mid + 1;
      printf("Setting high to %d\n", high);
    }
  }
  mid = (low+high) / 2;
  printf("final value of mid is %d\n", mid);
  return (x == v[mid]) ? mid: -1;
}
