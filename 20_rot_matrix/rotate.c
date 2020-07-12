#define SIZE 10
void rotate(char matrix[SIZE][SIZE]) {
  char clone[SIZE][SIZE];
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      clone[i][j] = matrix[i][j];
    }
  }
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      matrix[i][j] = clone[SIZE-1-j][i];
    }
  }
}
