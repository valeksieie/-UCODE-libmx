#include "libmx.h"

int mx_strlen(const char *s) {
   int count = 0; 
      for ( ; *s++ != '\0'; count++);
   return count;
}
