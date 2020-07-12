#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char * str) {
  if (str == NULL){
    printf("Encountered a null pointer, returning from reverse function\n");
    return;
  }
  int count = 0;
  while (str[count] != '\0') {
    count++; //count is size of string (not including null terminator, except when empty)
  }
  int max = count - 1; //max is highest index reached, valid for non-empty strings
  char str_new[count + 1]; //declare new string that is equal to size of "str" including null terminator
  str_new[count] = '\0';
  for (int i = 0; i < count; i++){ //in empty case the for-loop is not entered
    str_new[i] = str[max - i];
  }
  strncpy(str, str_new, (count+1));
}

int main(void) {
  char str0[] = "";
  // char * str0 = NULL;
  char str1[] = "123";
  char str2[] = "abcd";
  char str3[] = "Captain's log, Stardate 42523.7";
  char str4[] = "Hello, my name is Inigo Montoya.";
  char str5[] = "You can be my wingman anyday!";
  char str6[] = "Executor Selendis! Unleash the full power of your forces! There may be no tomorrow!";
  char * array[] = {str0, str1, str2, str3, str4, str5, str6};
  for (int i = 0; i < 7; i++) {
    reverse(array[i]);
    printf("%s\n", array[i]);
  }
  return EXIT_SUCCESS;
}
