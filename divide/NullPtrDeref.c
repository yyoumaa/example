//clang NullDePtr.c -o npd
//./npd
int main()
{
    *(int *)0 = 0; // Segmentation fault (core dumped)
}
