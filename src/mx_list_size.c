#include "libmx.h"

int mx_list_size(t_list *list) {
   int count = 0;
   t_list *tmp = NULL;

    if (list) {
       tmp = list;
      while (tmp != NULL) {
            count++;
            tmp = tmp->next;
      }
    }
    return count;
}
