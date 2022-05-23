#ifndef STRING_H
#define STRING_H

#include "global.h"

namespace strfun {

STRING_EXPORT void* memcpy(void* s1, const void* s2, size_t n);

STRING_EXPORT void* memmove(void* s1, const void* s2, size_t n);

STRING_EXPORT char* strcpy(char* s1, const char* s2);

STRING_EXPORT char* strncpy(char* s1, const char* s2, size_t n);

STRING_EXPORT char* strcat(char* s1, const char* s2);

STRING_EXPORT char* strncat(char* s1, const char* s2, size_t n);

STRING_EXPORT int memcmp(const void* s1, const void* s2, size_t n);

STRING_EXPORT int strcmp(const char* s1, const char* s2);

STRING_EXPORT int strcoll(const char* s1, const char* s2);

STRING_EXPORT int strncmp(const char* s1, const char* s2, size_t n);

STRING_EXPORT size_t strxfrm(char* s1, const char* s2, size_t n);

STRING_EXPORT char* strtok(char* s1, const char* s2);

STRING_EXPORT void* memset(void* s, int c, size_t n);

STRING_EXPORT char* strerror(int errnum);

STRING_EXPORT size_t strlen(const char* s);
}

#endif // STRING_H
