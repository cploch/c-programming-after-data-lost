#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n);

int main(void){
  int array1[] = {1,2,3,3,4,5};
  size_t longest_seq1 = maxSeq(array1, 6);
  printf( "%lu \n", longest_seq1);
  int array2[] = {5,4,3,2,1};
  size_t longest_seq2 = maxSeq(array2, 5);
  printf( "%lu \n", longest_seq2);
  int array3[] = {-1,1,2,3,4,5};
  size_t longest_seq3 = maxSeq(array3, 6);
  printf( "%lu \n", longest_seq3);
  int array4[] = {};
  size_t longest_seq4 = maxSeq(array4, 0);
  printf( "%lu \n", longest_seq4);
  int array5[] = {1,2,1,3,5,7,2,4,6,9};
  size_t longest_seq5 = maxSeq(array5, 10);
  printf( "%lu \n", longest_seq5);
  
  if (longest_seq1  != 3) {
    printf( "Array1 failed, answer = %lu \n", longest_seq1);
    return EXIT_FAILURE;
  }
  else if (longest_seq2 != 1) {
    printf( "Array2 failed, answer = %lu \n", longest_seq2);
    return EXIT_FAILURE;
  }
  else if (longest_seq3 != 6) {
    printf( "Array3 failed, answer = %lu \n", longest_seq3);
    return EXIT_FAILURE;
  }
  else if (longest_seq4 != 0) {
    printf( "Array4 failed, answer = %lu \n", longest_seq4);
    return EXIT_FAILURE;
  }
  else if (longest_seq5 != 4) {
    printf( "Array5 failed, answer = %lu \n", longest_seq5);
    return EXIT_FAILURE;
  }
  else{
    printf( "Array succeeded");
    return EXIT_SUCCESS;
  }
}
