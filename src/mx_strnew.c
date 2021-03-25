#include "libmx.h"

char *mx_strnew(const int size) {

    if (size < 0)
      return NULL;
    char *point = (char*)malloc(sizeof(char) * (size + 1));
        if (point == NULL)
    return NULL;
    for (int i = 0; i <= size; i++)
        point[i] = '\0';
    return point;
}
