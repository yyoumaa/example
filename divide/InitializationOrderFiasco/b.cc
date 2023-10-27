//clang++ a.cc b.cc -o iof
//./iof
int foo() { return 42; }
int extern_global = foo();
