#include "public.h"

bool isPow2(size_t size)
{
    return size && !(size & (size - 1));
}

uint32_t alignPow2(uint32_t size)
{
    size--;
    size |= size >> 1;
    size |= size >> 2;
    size |= size >> 4;
    size |= size >> 8;
    size |= size >> 16;

    return size + 1;
}
