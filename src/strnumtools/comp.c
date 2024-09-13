#include <stdlib.h>
// test
#include <stdio.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (*str != '\0')
    {
        str++;
        i++;
    }
    return (i);
}

static char space_as_num(char *str,int index)
{
    int len;

    len = ft_strlen(str);
    if (index < len)
        return (str[len - 1 - index]);
    else
        return ('0');
}

/// @brief `0 <= a < b`
///        unable to comp minus number. abs only
/// @param a 
/// @param b 
/// @return 
int lt_abs(char *a,char *b)
{
    int i;
    char a_char_tmp;
    char b_char_tmp;
    int flag;

    flag = 0;
    i = 0;
    while (1)
    {
        a_char_tmp = space_as_num(a,i);
        b_char_tmp = space_as_num(b,i);
        if (i >= ft_strlen(a) && i >= ft_strlen(b))
            break;
        if (a_char_tmp != b_char_tmp)
            flag = a_char_tmp < b_char_tmp;
        i++;
    }
    return (flag);
}

/// @brief `a < b`
///        able to comp minus number
/// @return 
// int lt(char *a,char *b)
// {

// }

