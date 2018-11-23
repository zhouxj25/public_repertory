#pragma once
#ifdef _cplusplus
#include <cstdlib>
#include <cstdint>
#else
#include <stdlib.h>
#include <stdint.h>
#endif

//check if N is power of 2
bool isPow2(size_t size);

//align N to power of 2
uint32_t alignPow2(uint32_t size);
