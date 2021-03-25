#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (fd < 0)
        return -2;

    static char *buff;
    int buf_pos = 0, line_pos = 0;
    //clean lineptr
    for (int i = 0; (*lineptr)[i] != '\0'; i++)
        (*lineptr)[i] = '\0';
    //read from buff
    while (buff == NULL || buff[buf_pos] != delim) {
        //fill buffer
        if (buff == NULL || *buff == '\0') {
            buff = mx_strnew(buf_size);
        if(!read(fd, buff, buf_size))
          return line_pos;
        }
        //copy char
        if (buff[buf_pos] != delim)
            (*lineptr)[line_pos++] = buff[buf_pos++];
        else
            break;

        //free buffer if ended
        if (buff[buf_pos] == '\0') {
            buf_pos = 0;
            mx_strdel(&buff);
        }
    }
    //advance buffer
    char *temp = mx_strdup(&buff[buf_pos+1]);
    mx_strcpy(buff, temp);
    mx_strdel(&temp);
return line_pos;
}
