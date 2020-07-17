#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  //WRITE ME
  char * outFileName = malloc((strlen(inputName) + 8) * sizeof(*outFileName));
  strcpy(outFileName, inputName);
  strcat(outFileName, ".counts");
  return outFileName;
}

/*
//outfileNAme is argv[2] + ".txt", so add 4 to its length.
char * outFileName = malloc((strlen(argv[2]) + 5) * sizeof(*outFileName)); //Mistake #1: space for null terminator was not malloced, so I changed "4" to "5".
strcpy(outFileName, argv[2]);
strcat(outFileName, ".enc");
*/
