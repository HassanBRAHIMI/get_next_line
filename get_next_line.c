/*
    daamn all roads lead to rome
    <----rome algo 101----->
       --00--> jm3 krk.  
       --01--> read till u find the newline
            --00--> intialize a variable int to store the return value of read
            --01--> use a loop as long as the read return is positive and there's no new line in the file
            --02--> join therm buffers
            --03--> handle special cases
                - error while reading
                - error while joining
                - make sure there's no leaks
                -(...........) i'll know of in the process
            --04-->  return the container
        --02--> treat the container
            --01--> lovely loop iterate in the container as long as there's some to iterate on[true]
             - iterate till u get to the new line or EOF
             -trim till the \n / \0 and call it g_line
            --02--> keep the g_line(the line that should be returned)
            --03--> deal with the container(chyata) [to use another time in join]
             - make sure there's no leaks
            --04--> return the g_line
    CONGRATS U GOT AN OPTIMIZED GET_NEXT_LINE !!!!
*/
#include "get_next_line.h"
void    read_from_file(int fd, char **raw_material)
{
   
    char    buffer[BUFFER_SIZE + 1];
    int     readed;

    readed = 1;
   
    while (readed > 0)
    {
        readed = read(fd, buffer, BUFFER_SIZE);
        if (readed <= 0) {
            free(*raw_material);
            *raw_material = NULL;                                                                             
            return ;
        }
        buffer[readed] = '\0';
            *raw_material = concatenate(*raw_material, buffer);
        if (find_nl(*raw_material))
            break;
    }
} 
char    *treat_container(char **the_rest)
{
    int i;
    char *deref = *the_rest;

    i = 0;
    if (the_rest && *the_rest)
    {
        while(deref[i])
        {
            if (deref[i] == '\n')
                return (sub_str(deref, 0, i + 1));
            i++;
        }
        if(deref[i] == '\0')
            return (sub_str(deref, 0, i));
    }
    return (NULL);
}

char    *trash_blender(char *trash)
{
    int i;
    char    *this;

    i = 0;
    while(trash[i] && trash[i] != '\n')
        i++;
    this = sub_str(trash, i + 1, ft_strlen(trash) - i);
    free(trash);
    trash = NULL;
    return(this);
}
char    *get_next_line(int fd)
{
    static char *container;
    char        *g_line;

    read_from_file(fd, &container);
    g_line = treat_container(&container);
    if (!g_line)
        return NULL;
    container = trash_blender(container);
    return (g_line);
}
// int main()
// {
//     int fd = open("meme.txt", O_RDONLY);
//     for (int i = 0; i < 9; i++)
//         printf("%s", get_next_line(fd));
// }