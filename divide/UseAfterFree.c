//clang++ UseAfterFree.c -o uaf
// ./uaf
int main(int argc, char **argv) {
  int *array = new int[100];
  delete [] array;
  return array[argc];  // BOOM
}
