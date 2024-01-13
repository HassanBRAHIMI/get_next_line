#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 13
#endif
#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE
char	*sub_str(char *s, unsigned int start, size_t len);
void    read_from_file(int fd, char **raw_material);
char    *get_next_line(int fd);
int ft_strlen(char *s);
char    *str_dup(char *str);
char    *concatenate(char *s1, char *s2);
int find_nl(char *str);
#endif