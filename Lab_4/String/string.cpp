#include "string.h"

namespace strfun {

char* strcpy(char* s1, const char* s2){
    char* start = s1;
    while(*s2 != '\0'){
        *s1++ = *s2++;
    }
    *s1++ = '\0';
    return start;
}

char* strncpy(char* s1, const char* s2, size_t n){
    char* start = s1;
    while(n--){
        *s1++ = *s2++;
        if(!n){
            return start;
        }
    }
    while(n--){
        *s1++ = '0';
    }
    return start;
}

int strcmp(const char* s1, const char* s2){
    while(*s1++ == *s2++){}
    return *s1 - *s2;
}

int strncmp(const char* s1, const char* s2, size_t n){
    while(n-- && *s1++ == *s2++){}
    return *s1 - *s2;
}

void* memcpy(void* s1, const void* s2, size_t n){
    char* dp = reinterpret_cast<char*>(s1);
    const char *sp = reinterpret_cast<const char*>(s2);
    while (n--)
        *dp++ = *sp++;
    return s1;
}

void* memmove(void* s1, const void* s2, size_t n) {
    unsigned char *pd = reinterpret_cast<unsigned char*>(s1);
    const unsigned char *ps = reinterpret_cast<const unsigned char*>(s2);
    if(ps == pd)
        return s1;
    if (ps < pd && ps + n >= pd) {
        for (pd += n, ps += n; n--;) {
            *--pd = *--ps;
        }
    }
    else {
        while(n--) {
            *pd++ = *ps++;
        }
    }
    return s1;
}

char* strcpy(char* s1, const char* s2);

char* strncpy(char* s1, const char* s2, size_t n);

char* strcat(char* s1, const char* s2){
    char* start = s1;
    while(*s1){
        ++s1;
    }
    while(*s2){
        *s1++ = *s2++;
    }
    return start;
}
char* strncat(char* s1, const char* s2, size_t n){
    char* start = s1;
    while(*s1){
        ++s1;
    }
    while(n--){
        if(*s2){
            *s1++ = *s2++;
        }
    }
    return start;
}
int memcmp(const void* s1, const void* s2, size_t n){
    const unsigned char *pd = reinterpret_cast<const unsigned char*>(s1);
    const unsigned char *ps = reinterpret_cast<const unsigned char*>(s2);
    while(n--){
        if(*pd != *ps) {
            return *pd - *ps;
        }
        else {
            ++pd;
            ++ps;
        }
    }
    return 0;
}

int strcoll(const char* /*s1*/, const char* /*s2*/){
    return 0;
}

size_t strxfrm(char* /*s1*/, const char* /*s2*/, size_t /*n*/) {
    return 0;
}

char* strtok(char* s1, const char* s2){
    static char* stop = 0;
    const char* delim = s2;
    if(s1 != nullptr){
        stop = s1;
    } else if(!stop){
        return 0;
    } else if(s1 == nullptr){
        s1 = stop;
    }
    while(*stop){
        while(*s2){
            if(*stop == *s2){

                if(stop - s1 == 0){
                    ++s1;
                } else{
                    *stop  = '\0';
                    ++stop;
                    return s1;
                }
            }
            ++s2;
        }
        s2 = delim;
        ++stop;
    }
    if(stop == s1){
        return stop = 0;
    }
    return s1;
}

void* memset(void* s, int c, size_t n){
    char* ps = reinterpret_cast<char*>(s);
    while(n--){
        *ps++ = c;
    }
    return s;
}

char* strerror(int /*errnum*/){
    char* stop = 0;
    return stop;
}



size_t strlen(const char* s){
    size_t len = 0;
    while(s[len] != '\0'){
        ++len;
    }
    return len;
}
}
