#include "memalign.h"
#include "public.h"

void *alignMalloc(void **ptr, size_t align, size_t size)
{
   if (size <= 0 || align <=0 || !isPow2(align))
        return nullptr;

   void *alignPtr(nullptr);
#ifdef  HAVE_MEMALIGN 
   *ptr = memalign(align, size);
#elif HAVE_POSIX_MEMALIGN 
   posix_memalign(ptr, align, size);
#elif HAVE_ISOC11_MEMALIGN
   *ptr = aligned_alloc(align, size);
#elif HAVE_MING_MEMALIGN
   *ptr = __mingw_aligned_malloc(size, align);
#elif HAVE_MSC_MEMALIGN 
   *ptr = _aligned_malloc(size, align);
#else
#if(defined __WORDSIZE && (__WORDSIZE == 64)) || defined _WIN64
   if (align <= 16)
        *ptr = malloc(size);
#else
   if (align <= 8)
        *ptr = malloc(size);
#endif
   else
   {
        *ptr = malloc(size + align);
        size_t intptr = size_t(*ptr);
        size_t aligned = (intptr - 1 + align) & -align;
        size_t diff = aligned - intptr;
        if ((size + diff) > (size + align))
                return nullptr;
        else
        {
                alignPtr = (void*)aligned;
        }
   }
#endif
   if (!alignPtr)
        alignPtr = *ptr;

   return alignPtr;
}

void alignFree(void* ptr)
{
#if defined HAVE_MING_MEMALIGN
    __mingw_aligned_free(ptr);
#elif defined HAVE_MSC_MEMALIGN
    _aligned_free(ptr);
#else
    free(ptr);
#endif
}

