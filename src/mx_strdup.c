#include "libmx.h"

char *mx_strdup(const char *str) {
    char *cpy = mx_strnew(mx_strlen(str));
        if (cpy == NULL)
    return NULL;
return mx_strcpy(cpy, str);
}
