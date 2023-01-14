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
    int res;
    while ((*str1 != '\0') && (*str1 - *str2 == 0)) {
        str1++;
        str2++;
    }
    res = *str1 - *str2;
    return res;
}

int lib_strncmp(const char *str1, const char *str2, lib_size_t n) {
    int res = 0;
    char *temp1 = (char *) calloc (1, lib_strlen(str1));
    char *temp2 = (char *) calloc (1, lib_strlen(str2));
    for (lib_size_t i = 0; i < n; i++) {
        temp1[i] = str1[i];
        temp2[i] = str2[i];    
    }
    res = lib_strcmp(temp1, temp2);
    free(temp1);
    free(temp2);
    return res;
}

void *lib_memchr(const void *str, int c, lib_size_t n) { // нужно больше тестов
    void *res = lib_NULL;
    int flag = 0;
    char *temp_str = (char *) str;
    lib_size_t i = 0;
    for (i = 0; i < n; i++) {
        if (temp_str[i] == c) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        res = temp_str;
    }
    return res;
}

void *lib_memcpy(void *dest, const void *src, lib_size_t n) { //нужно больше тестов
    void *res = dest;
    char *temp_dest = (char *) dest;
    const char *temp_src = (const char *) src;
    if (temp_dest != lib_NULL && temp_src != 0) {
        for (lib_size_t iterator = 0; iterator < n; iterator++) {
            *temp_dest++ = *temp_src++;
        }
    }
    return res;
}

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

// char *lib_strcpy(char *dest, const char *src) {
//     char *res = dest; // *temp_dest_str = dest;
//     lib_strlen(src);
//     //const char *temp_src_str = (const char *) src;
    
//     lib_size_t iterator = 0;
//     // if (temp_dest_str != lib_NULL && temp_src_str != 0) {
//         while (iterator != 10) {
//             // temp_dest_str[iterator] = temp_src_str[iterator];
//             iterator++;
//         }
//     // }
//     return res;
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