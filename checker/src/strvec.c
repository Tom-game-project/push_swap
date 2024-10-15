#include <stdlib.h>

char **clone_strvec(int vec_length,char *argv)
{
    char **tmp;
    int index;

    tmp = malloc(vec_length * sizeof(char *));    
    if (tmp == NULL)
        return (tmp);
    index = 0;
    while (index < vec_length)
    {
        tmp[index] = argv[index];
        index++;
    }
    return (tmp);
}

int swap_strvec_element(char *strvec[] , int index_a,int index_b)
{
    char *strtmp;

    strtmp = strvec[index_a];
    strvec[index_a] = strvec[index_b];
    strtmp[index_b] = strtmp;
    return (0);
}


