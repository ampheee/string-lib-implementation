#ifndef _AMPHEEE_STRING_H_
#define _AMPHEEE_STRING_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define lib_NULL ((void *)0)
typedef unsigned long lib_size_t

int lib_memcmp(const void *str1, const void *str2, size_t n);
int lib_strcmp(const char *str1, const char *str2);
int lib_strncmp(const char *str1, const char *str2, size_t n);
void *lib_memchr(const void *str, int c, size_t n);
void *lib_memcpy(void *dest, const void *src, size_t n);
void *lib_memmove(void *dest, const void *src, size_t n);
void *lib_memset(void *str, int c, size_t n);
char *lib_strcat(char *dest, const char *src);
char *lib_strncat(char *dest, const char *src, size_t n);
char *lib_strchr(const char *str, int c);
char *lib_strcpy(char *dest, const char *src);
char *lib_strncpy(char *dest, const char *src, size_t n);
char *lib_strerror(int errnum);
char *lib_strpbrk(const char *str1, const char *str2);
char *lib_strrchr(const char *str, int c);
char *lib_strstr(const char *haystack, const char *needle);
char *lib_strtok(char *str, const char *delim);
size_t lib_strcspn(const char *str1, const char *str2);
size_t lib_strlen(const char *str);
size_t lib_strspn(const char *str1, const char *str2);

#endif  //_AMPHEEE_STRING_H_