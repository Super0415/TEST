#ifndef _EXTERN_H
#define _EXTERN_H

#ifdef PUBLIC
        #undef PUBLIC
#endif
#define PUBLIC extern

#ifdef PRIVATE
        #undef PRIVATE
#endif
#define PRIVATE static

#endif /*_EXTERN_H*/