#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

#include <assert.h>

void stripNewline(char * str) {
  char * q = strchr(str, '\n');
  if (q != NULL) {
    *q = '\0';
  }
}

void addToArray(char * line, size_t size, char * value, char * key){
  char * p = strchr(line, '=');
  strncpy(value, p+1, size);
  *p = '\0';
  strncpy(key, line, size);
}

kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  //open the file
  FILE * f = fopen(fname, "r");
  if (f == NULL) {
    return NULL; //Could not open file->indicate failure
  }

  kvarray_t * answer = malloc(sizeof(*answer));
  answer->length = 0;
  answer->array = malloc(sizeof(answer->array));

  char * line = NULL;
  size_t size = 0;

  size_t num_lines = 0;

  //read the lines of text
  while (getline(&line, &size, f) != -1){
    stripNewline(line);
    answer->array = realloc(answer->array, sizeof(answer->array)*(num_lines+1));
    answer->array[num_lines] = malloc(sizeof(kvpair_t));
    answer->array[num_lines]->key = malloc(size*sizeof(char));
    answer->array[num_lines]->value = malloc(size*sizeof(char));
    //split them into key/value pairs
    //add the resulting pairs to an array
    addToArray(line, size, answer->array[num_lines]->value, answer->array[num_lines]->key);
    /*char * p = strchr(line, '=');
    strncpy(answer->array[num_lines]->value, p+1, size);
    *p = '\0';
    strncpy(answer->array[num_lines]->key, line, size);*/
    num_lines++;
    answer->length = num_lines;
    line = NULL;
    size = 0;      
  }
  //close the file
  int result = fclose(f);
  assert(result == 0);
  //return the kvarray_t * that has your array
  return answer;
}

void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  for (int i = 0; i < pairs->length; i++){
    free(pairs->array[i]->key);
    free(pairs->array[i]->value);
    free(pairs->array[i]);
  }
  free(pairs->array);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  for (int i = 0; i < pairs->length; i++){
    printf("key = '%s' value = '%s'\n", pairs->array[i]->key, pairs->array[i]->value);
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
  int result = 0;
  for (int i = 0; i < pairs->length; i++){
    result = strcmp(pairs->array[i]->key, key);
    if (result == 0){
      return pairs->array[i]->value;
    }
  }
  return NULL;
}
