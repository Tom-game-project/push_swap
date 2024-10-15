#include <unistd.h>

static int ft_strlen(char *str)
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

void print_error()
{
    write(STDERR_FILENO, "Error\n", 6);
}

void put_str(char *str)
{
    write(STDOUT_FILENO, str, ft_strlen(str));
}
