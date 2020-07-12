#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n)
{
  if (n < 1) {
    return 0;
  }
  size_t increment = 1;
  size_t max_increment = 1;
  for (size_t i = 0; i < (n-1); i++) {
    if (array[i+1] > array[i]) {
      increment ++;
      if (increment > max_increment) {
	max_increment = increment;
      }
    }
    else {
      increment = 1;
    }
  }
  return max_increment;
}
