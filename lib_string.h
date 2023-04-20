#ifndef _LIB_STRING_H_
#define _LIB_STRING_H_

#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>

#include "lib_errors.h"
typedef long unsigned lib_size_t;
#define lib_NULL ((void *)0)
#define BUFF_SIZE 4096

//taken from en.cppreference.com/w/cpp/types/climits
#define MAX_INT   2147483647
#define MAX_LLONG 9223372036854775807LL
#define MAX_ULONG 18446744073709551615ULL
#define TOL 0.000001


int lib_memcmp(const void *str1, const void *str2, lib_size_t n);
int lib_strcmp(const char *str1, const char *str2);
int lib_strncmp(const char *str1, const char *str2, lib_size_t n);
void *lib_memchr(const void *str, int c, lib_size_t n);
void *lib_memcpy(void *dest, const void *src, lib_size_t n);
void *lib_memmove(void *dest, const void *src, lib_size_t n);
void *lib_memset(void *str, int c, lib_size_t n);
char *lib_strcat(char *dest, const char *src);
char *lib_strncat(char *dest, const char *src, lib_size_t n);
char *lib_strchr(const char *str, int c);
char *lib_strcpy(char *dest, const char *src);
char *lib_strncpy(char *dest, const char *src, lib_size_t n);
char *lib_strerror(int errnum);
char *lib_strpbrk(const char *str1, const char *str2);
char *lib_strrchr(const char *str, int c);
char *lib_strstr(const char *haystack, const char *needle);
char *lib_strtok(char *str, const char *delim);
lib_size_t lib_strcspn(const char *str1, const char *str2);
lib_size_t lib_strlen(const char *str);
lib_size_t lib_strspn(const char *str1, const char *str2);

void *lib_to_upper(const char *str);
void *lib_to_lower(const char *str);
void *lib_insert(const char *src, const char *str, lib_size_t start_index);
void *lib_trim(const char *src, const char *trim_chars);

char *trim_reverse(const char *src);

int lib_sscanf(const char *str, const char *format, ...);
int lib_sprintf(char *str, const char *format, ...);

bool isBasedDigit(char c, int b);
long long lib_atoi(char *sptr);

#endif  //_LIB_STRING_H_