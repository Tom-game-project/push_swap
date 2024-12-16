/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:16:56 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/16 17:05:59 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

int	print_error(void)
{
	return (write(STDERR_FILENO, "Error\n", 6));
}

int	print_allocation_error(void)
{
	return (write(STDERR_FILENO, "Allocation Error Occured\n", 6));
}

void	put_str(char *str)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
}
