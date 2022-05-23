#ifndef GLOBAL_H
#define GLOBAL_H

#if defined(STRING_LIBRARY)
#  define STRING_EXPORT __declspec(dllexport)
#else
#  define STRING_EXPORT __declspec(dllimport)
#endif

#endif // GLOBAL_H
