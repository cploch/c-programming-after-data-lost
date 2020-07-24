#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  //WRITE ME
  counts_t * answer = malloc(sizeof(*answer));
  answer->size = 0;
  answer->array = NULL;
  return answer;
}
void addCount(counts_t * c, const char * name) {
  //WRITE ME
  int found = 0;
  if (name == NULL){
    name = "NULL";
  }
  for (int i = 0; i < c->size; i++){
    int result = strcmp(name, c->array[i]->str);
    if (result == 0){
      c->array[i]->count++;
      found = 1;
    }
  }
  if (found == 0){
    c->size++;
    c->array = realloc(c->array, sizeof(*c->array)*(c->size));
    c->array[c->size-1] = malloc(sizeof(*c->array[c->size-1]));
    c->array[c->size-1]->str = malloc((strlen(name)+1));
    strcpy(c->array[c->size-1]->str, name);
    c->array[c->size-1]->count = 1;
  }                
  
}
void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
  int foundNull = 0;
  int indexNull = 0;
  int resultNull = 0;
  for (int i = 0; i < c->size; i++){
    resultNull = strcmp(c->array[i]->str, "NULL");
    if (resultNull == 0){
      foundNull = 1;
      indexNull = i;
    }
    else{
      fprintf(outFile, "%s: %d\n", c->array[i]->str, c->array[i]->count);
    }
  }
  if (foundNull == 1){
    fprintf(outFile, "<unknown> : %d\n", c->array[indexNull]->count);
  }
}

void freeCounts(counts_t * c) {
  //WRITE ME
  for (int i = 0; i < c->size; i++){
    free(c->array[i]->str);
    free(c->array[i]);
  }
  free(c->array);
  free(c);
}
