#ifndef LIBMX_H
#define LIBMX_H

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <malloc/malloc.h>

/*------- UTILS PACK -------*/

//basic
void mx_printchar(char c);                                                             
void mx_printstr(const char *s);
void mx_print_strarr(char **arr, const char *delim);
void mx_printint(int n);
char *mx_nbr_to_hex(unsigned long nbr);
int mx_bubble_sort(int *arr, int size);
char *mx_itoa(int number);

//advanced
void mx_print_unicode(wchar_t c);
double mx_pow(double n, unsigned int pow);
int mx_sqrt(int x);
unsigned long mx_hex_to_nbr(const char *hex);
void mx_foreach(int *arr, int size, void (*f)(int));
int mx_binary_search(char **arr, int size, const char *s, int *count);

/*------- STRINGS PACK -------*/

//basic
int mx_strlen(const char *s);
void mx_swap_char(char *s1, char *s2);
char *mx_strcpy(char *dst, const char *src);
int mx_strcmp(const char *s1, const char *s2);
char *mx_strcat(char *restricts1, const char* restricts2);
char *mx_strnew(const int size);
char *mx_strdup(const char *s1);
char *mx_strjoin(const char *s1, const char *s2);
void mx_strdel(char **str);
void mx_del_strarr(char ***arr)
char *mx_file_to_str(const char *file);
int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd);

//advanced
char *mx_strncpy(char *dst, const char *src, int len);
void mx_str_reverse(char *s);
char *mx_strndup(const char *s1, size_t n);
char *mx_strstr(const char *haystack, const char *needle);
int mx_count_words(const char *str, char c);
int mx_count_substr(const char *str, const char *sub);
int mx_get_char_index(const char *str, char c);
int mx_get_substr_index(const char *str, const char *sub);
char *mx_strtrim(const char *str);
char *mx_del_extra_spaces(const char *str);
char **mx_strsplit(const char *s, char c);
char *mx_replace_substr(const char *str, const char *sub, const char *replace);

/*------- MEMORY PACK -------*/

//basic
void *mx_memset(void *b, int c, size_t len);
void *mx_memcpy(void *restrictdst, const void *restrictsrc, size_t n);
int mx_memcmp(const void *s1, const void *s2, size_t n);
void *mx_realloc(void *ptr, size_t size);

//advanced
void *mx_memmove(void *dst, const void *src, size_t len);
void *mx_memrchr(const void *s, int c, size_t n);
void *mx_memccpy(void *restrictdst, const void *restrictsrc, int c, size_t n);
void *mx_memchr(const void *s, int c, size_t n);
void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len);

/*------- LIST PACK -------*/

typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

//basic
t_list *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);
void mx_push_back(t_list **list, void *data);
void mx_pop_front(t_list **head);
void mx_pop_back(t_list **head);

//advanced
int mx_list_size(t_list *list);
t_list *mx_sort_list(t_list *lst, bool(*cmp)(void *, void *));

/*------- EXTRA PACK -------*/

int mx_tolower(int c);
int mx_toupper(int c);
int mx_atoi(const char *str);
int mx_strncmp(const char *s1, const char *s2, int n);
bool mx_isspace(int c);
bool mx_isalpha(int c);
bool mx_isdigit(int c);
bool mx_islower(int c);
bool mx_isupper(int c);

#endif