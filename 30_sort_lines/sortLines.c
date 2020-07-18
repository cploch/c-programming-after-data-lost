#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

char ** readInLines(FILE * f, size_t * num_lines) {
  char * line= NULL;
  size_t sz =0;
  char ** array = NULL;
  size_t n = 0;
  while(getline(&line, &sz, f) > 0){
    n++;
    array=realloc(array, n * sizeof(*array));
    array[n-1] = NULL;
    array[n-1]=realloc(array[n-1], strlen(line)*(sizeof(**array)+1));
    strcpy(array[n-1], line);
  }
  *num_lines = n;
  free(line);
  return array;
}


void printData(char ** array, size_t num_lines) {
  for (size_t i = 0; i < num_lines; i++) {
    printf("%s\n", array[i]);
    //free(&array[i]);
    free(array[i]);
  }
  free(array);
}

int main(int argc, char ** argv) {
  size_t num_lines = 0;
  if (argc == 1){
    //read lines from standard input
    char ** array = readInLines(stdin, &num_lines);
    //sort the lines of input
    sortData(array, num_lines);
    //print the results
    printData(array, num_lines);
  }
  else if (argc > 1){
    //for each argument:
    for (int num_args = 1; num_args < argc; num_args ++){
      //open the file
      FILE * f = fopen(argv[num_args],"r");
      if (f == NULL){
	fprintf(stderr, "Error: fopen failed, meaning file did not exist.");
	return EXIT_FAILURE;
      }
      //read all lines of data from file
      size_t num_lines = 0;
      char ** array = readInLines(f, &num_lines); 
      //sort the lines
      sortData(array, num_lines);
      //print the results
      printData(array, num_lines);
      //close the file
      fclose(f);
    }
  }
  else {
    fprintf(stderr, "Error: argc does not fall into either the = 1 case or the > 1 case.");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}


