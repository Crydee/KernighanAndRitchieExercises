/* Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside).  write a version */
/* with only one test inside the loop and measure the difference in run-time. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEST_ARR_SIZE 2000000

int binsearch(int x, int v[], int n);
int mod_binsearch(int x, int v[], int n);
int rand_int(int lower, int upper);

main() {
  int ii, test_arr[TEST_ARR_SIZE];
  float time_diff;
  clock_t start_time;

  /* Construct a test array with weakly monotonically increasing values. */
  for (ii = 0; ii < TEST_ARR_SIZE; ii++)
    test_arr[ii] = (ii == 0) ? 0: rand_int(test_arr[ii - 1], test_arr[ii - 1] + 3);


// Run the modified binary search algo TEST_ARR_SIZE times
  start_time = clock();
  /* For each element in the array, execute the binary search routine to find it. */
  for (ii = 0; ii < TEST_ARR_SIZE; ii++) {
    mod_binsearch(test_arr[ii], test_arr, TEST_ARR_SIZE);
    //printf("the value %d is at index %d\n", test_arr[ii], mod_binsearch(test_arr[ii], test_arr, TEST_ARR_SIZE));
  }
  time_diff = clock() - start_time;
  printf("The modified binary search took %f clocks to run %d times.\n", time_diff, TEST_ARR_SIZE);

// Run the book algo TEST_ARR_SIZE times
  start_time = clock();
  /* For each element in the array, execute the binary search routine to find it. */
  for (ii = 0; ii < TEST_ARR_SIZE; ii++) {
    binsearch(test_arr[ii], test_arr, TEST_ARR_SIZE);
    //printf("the value %d is at index %d\n", test_arr[ii], mod_binsearch(test_arr[ii], test_arr, TEST_ARR_SIZE));
  }
  time_diff = clock() - start_time;
  printf("The book binary search took %f clocks to run %d times.\n", time_diff, TEST_ARR_SIZE);

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

/* find x in v[0] <= v[1] <= ... <= v[n-1] */
int mod_binsearch(int x, int v[], int n) {
  int low, high, mid;
  /* low and high bound the search value.  high stays higher than the index of the
   * first occurrence of the search value, and low stays lower. */
  low = -1;
  high = n;
  /* Keep iterating until there is only one index between low and high */
  while (low + 2 < high) {
    mid = (low+high) / 2;
    if (x > v[mid]) {
      low = mid;
    }
    else {
      high = mid + 1;
    }
  }
  mid = (low+high) / 2;
  return (x == v[mid]) ? mid: -1;
}

/* Generate a random integer in the range [lower, upper] */
int rand_int(int lower, int upper) {
  int rand_val;
  /* note that the max value of the return value of rand() is guaranteed to be at least 32767 */
  if (upper >= lower)
    return rand_val = (rand() % (upper - lower + 1)) + lower;
  else {
    printf("The upper bound must not be lower than the lower bound.  Provided vals: upper=%d, lower=%d\n", upper, lower);
    return -1;
  }
}

