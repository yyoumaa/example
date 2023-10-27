//clang++ vuln.c -o vuln
//./vuln
#include <stdlib.h>
#include <stdio.h>
void *p;
int memory_leak(){
  p = malloc(7);
  p = 0; // The memory is leaked here.
  return 0;
}

int *ptr;
__attribute__((noinline))
void FunctionThatEscapesLocalObject() {
  int local[100];
  ptr = &local[0];
}

volatile int *xp = 0;

int main(int argc, char **argv) {
  //MemoryLeak
  memory_leak();

  //StackOutOfBounds
  int stack_array[100];
  stack_array[1] = 0;
  printf("%d",stack_array[argc + 100]);  // BOOM

  //HeapOutOfBounds
  int *array = new int[100];
  array[0] = 0;
  int res = array[argc + 100];  // BOOM
  delete [] array;
  printf("%d",res);

    //UseAfterReturn
  FunctionThatEscapesLocalObject();
  printf("%d",ptr[argc]);

    //UseAfterScope
  {
    int x = 0;
    xp = &x;
  }
  *xp = 5;
  
  //NullPtrDeref
  *(int *)0 = 0; // Segmentation fault (core dumped)
  return 0;
}
