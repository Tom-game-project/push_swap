/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:17:18 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/16 17:11:36 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strnumtools.h"

static char	space_as_num(char *str, int index)
{
	int	len;

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
static int	lt_abs(char *a,char *b)
{
	int		i;
	char	a_char_tmp;
	char	b_char_tmp;
	int		flag;

	flag = 0;
	i = 0;
	while (i < ft_strlen(a) || i < ft_strlen(b))
	{
		a_char_tmp = space_as_num(a, i);
		b_char_tmp = space_as_num(b, i);
		if (a_char_tmp != b_char_tmp)
			flag = a_char_tmp < b_char_tmp;
		i++;
	}
	return (flag);
}

static int	ge_abs(char *a, char *b)
{
	int		i;
	char	a_char_tmp;
	char	b_char_tmp;
	int		flag;

	flag = 0;
	i = 0;
	while (i < ft_strlen(a) || i < ft_strlen(b))
	{
		a_char_tmp = space_as_num(a, i);
		b_char_tmp = space_as_num(b, i);
		if (a_char_tmp != b_char_tmp)
			flag = a_char_tmp >= b_char_tmp;
		i++;
	}
	return (flag);
}

static int	lt_helper(char *a,char *b,int a_is_minus, int b_is_minus)
{

	if (a_is_minus != b_is_minus)
		return (a_is_minus && !b_is_minus);
	if (a_is_minus && b_is_minus)
		return (ge_abs(a, b));
	return (lt_abs(a, b));
}

/// @brief `a < b`
///        able to comp minus number
/// @return 
/// "-100" < "21309" -> true
///
int	lt(char *a, char *b)
{
	int	a_is_minus;
	int	b_is_minus;

	a_is_minus = 0;
	b_is_minus = 0;
	if (a[0] == '-')
	{
		a_is_minus = 1;
		a++;
	}
	if (b[0] == '-')
	{
		b_is_minus = 1;
		b++;
	}
	return (lt_helper(a, b, a_is_minus, b_is_minus));
}

