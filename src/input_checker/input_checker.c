/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:14:34 by tmuranak          #+#    #+#             */
/*   Updated: 2024/11/07 21:14:35 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../src/strnumtools/strnumtools.h"
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

int is_in_int_range(char *arg)
{
	return (lt("-2147483649", arg) && lt(arg ,"2147483648"));
}

int is_valid_all(int argc, char *argv[])
{
    int i;

    i = 0;
    while (++i < argc)
    {
        if (!is_valid_string(argv[i]) || !is_in_int_range(argv[i]))
            return (0);
    }
    return (1);
}
