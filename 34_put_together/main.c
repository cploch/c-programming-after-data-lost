#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

#include <assert.h>

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  //WRITE ME
  counts_t * answer = createCounts();
  char * key = NULL;
  size_t size = 0;
  FILE * fInput = fopen(filename, "r");
  if (fInput == NULL){
    fprintf(stderr, "Error: input fopen failed.\n");
    exit(EXIT_FAILURE);
  }
  while (getline(&key, &size, fInput) != -1){
    stripNewline(key);
    char * value = lookupValue(kvPairs, key);
    addCount(answer, value);
  }
  free(key);
  int result = fclose(fInput);
  assert(result == 0);
  return answer;
}

int main(int argc, char ** argv) {
  //WRITE ME (plus add appropriate error checking!)
 //read the key/value pairs from the file named by argv[1] (call the result kv)
  if (argc < 3){
    fprintf(stderr, "Error: There are fewer than 2 arguments. There must be at least 2.\n");
    return EXIT_FAILURE;
  }
  kvarray_t * kv = readKVs(argv[1]);
 //count from 2 to argc (call the number you count i)
  for (int i = 2; i < argc; i++){
    //count the values that appear in the file named by argv[i], using kv as the key/value pair
    //   (call this result c)
    counts_t * c = countFile(argv[i], kv); 
    //compute the output file name from argv[i] (call this outName)
    char * outName = malloc(strlen(argv[i]) + 8);
    strcpy(outName, argv[i]);
    strcat(outName, ".counts");
    //open the file named by outName (call that f)
    FILE * f = fopen(outName, "w");
    if (f == NULL) {
      fprintf(stderr, "Error: output fopen failed.\n");
      return EXIT_FAILURE;
    }
    //print the counts from c into the FILE f
    printCounts(c, f);
    //close f
    int result = fclose(f);
    assert(result == 0);
    //free the memory for outName and c
    free(outName);
    freeCounts(c);

  }
 //free the memory for kv
  freeKVs(kv);
  return EXIT_SUCCESS;
}
