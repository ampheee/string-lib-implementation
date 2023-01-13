#include "lib_string.h"

// int lib_memcmp(const void *str1, const void *str2, size_t n) {
//     int res = 0;
//     for(int i=0; i<n && (str1+i != NULL) && (str2 + i) != NULL; ++i) {
//         if ( *(char*)(str1+i) > *(char*)(str2+i) ) {
//             res = 1;
//             break;
//         } else if ( *(char*)(str1+i) < *(char*)(str2+i) ) {
//             res = -1;
//             break;
//         }
//     }
//     return res;
// }

int lib_strcmp(const char *str1, const char *str2) {
    int res = 0, temp1 = 0, temp2 = 0;
    size_t len1 = lib_strlen(str1), len2 = lib_strlen(str2);
    size_t minLen = len1 > len2 ? len2 : len1;
    if (len1 == 0 && len2 == 0) {
        res = 0;
    } else {
        for (size_t i = 0; i < minLen; i+= sizeof(char)) {
            temp1 += str1[i];
            temp2 += str2[i];
        }
        res = temp1 > temp2 ? 1 : -1;
    }
    return res;
}

// int lib_strncmp(const char *str1, const char *str2, size_t n) {
//     int res = 0;
    
// }

// void *lib_memchr(const void *str, int c, size_t n) {
//     void* res = NULL;
//     if(str != NULL) {
//         for(int i=0; (str+i)!= NULL && i<n; ++i) {
//             if(*(char*)(str+i) == c) {
//                 //printf("%d", *(str+i));
//                 res = (void*)(str+i);
//                 break;
//             }
//         }
//     }
//     return res;
// }

// void *memcpy(void *dest, const void *src, size_t n) { 

// }

// void *lib_memmove(void *dest, const void *src, size_t n) {
    
// }

// void *lib_memset(void *str, int c, size_t n) {

// }

// char *lib_strcat(char *dest, const char *src) {

// }

// char *lib_strncat(char *dest, const char *src, size_t n) {

// }

char *lib_strchr(const char *str, int c) {
    char *res;
    int flag = 0;
    size_t iterator = 0;
    while (true) {
        if (str[iterator] == c || (str[iterator] == '\0' && c == '\0')) {
            flag = 1;
            break;
        } else if (str[iterator] == '\0') {
            break;
        }
        iterator += sizeof(char);
    }
    if (flag == 0) {
        res = NULL;
    } else {
        res = (char *) str + iterator;
    }
    return res;
}

// char *strcpy(char *dest, const char *src) {

// }

// char *strncpy(char *dest, const char *src, size_t n) {

// }

// char *strerror(int errnum) {

// }

// char *strpbrk(const char *str1, const char *str2) {

// }

// char *strrchr(const char *str, int c) {

// }

// char *strstr(const char *haystack, const char *needle) {

// }

// char *lib_strtok(char *str, const char *delim) {

// }

// size_t lib_strcspn(const char *str1, const char *str2) {

// }

size_t lib_strlen(const char *str) {
    size_t res = 0;
    while (str[res] != '\0') {
        res += sizeof(char);
    }
    return res;
}

// size_t lib_strspn(const char *str1, const char *str2) {
    
// }