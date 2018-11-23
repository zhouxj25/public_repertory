#include "memalign.h"

int main()
{
    void *ptr;
    void *alignPtr = alignMalloc(&ptr, 64, 100);
    alignFree(ptr);
    return 0;
}
