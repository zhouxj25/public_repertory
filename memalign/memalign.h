/*
 * allocate size bytes with an alignment of ALIGNMENT
 * @author zhouxj
 * @version 1.0, 2018-11-23
 */
#if !defined __APPLE__ && !defined __unix__ && !defined __linux__ \
    && !defined  _WIN32 && !defined __MING32__
#error "This system is not supported!"
#endif

#ifdef __linux__
#define HAVE_MEMALIGN
#endif

#if (defined _POSIX_C_SOURCE && (_POSIX_C_SOURCE >= 201112L)) \
    || defined __APPLE__
#define HAVE_POSIX_MEMALIGN
#endif

#if defined __MING32__ || defined __MING64__
#define HAVE_MING_MEMALIGN
#endif

#ifdef __USE_IOSC11
#define HAVE_IOSC11_MEMALIGN
#endif

#if defined _MSC_VER && (_MSC_VER > 1200)
#define HAVE_MSC_MEMALIGN
#endif

#if defined HAVE_MEMALIGN || defined HAVE_MING_MEMALIGN
#include <malloc.h>
#elif defined __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif


#if !defined __cplusplus || __cplusplus < 201103L
#define nullptr NULL
#endif

/*
 * @param  *ptr keep the memory which to be free in the future
 * @return the aligned memory address or nullptr
 */
void *alignMalloc(void **ptr, size_t align, size_t size);

void alignFree(void* ptr);

