#define NUM_CHAR 48

static int is_num_char(char c)
{
    int i;

    i = 0;
    while (i < 10)
    {
        if (NUM_CHAR + i == c)
            return (1);
        i++;
    }
    return (0);
}

int is_valid_string(char *str)
{
    int flag;

    flag = 0;
    if (*str == '-')
        str++;
    while (*str != '\0')
    {
        if (!is_num_char(*str))
            return (0);
        flag = 1;
        str++;
    }
    return (flag);
}

int is_valid_all(int argc, char *argv[])
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (!is_valid_string(argv[i]))
            return (0);
        i++;
    }
    return (1);
}
