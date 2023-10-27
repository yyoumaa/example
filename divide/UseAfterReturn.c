//clang UseAfterReturn.c -o uar
// ./uar
#include<stdio.h>
int *ptr;
__attribute__((noinline))
void FunctionThatEscapesLocalObject() {
  int local[100];
  ptr = &local[0];
}

int main(int argc, char **argv) {
  FunctionThatEscapesLocalObject();
  printf("yj");
  return ptr[argc];
}
