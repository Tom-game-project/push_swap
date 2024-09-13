/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:59:02 by tmuranak          #+#    #+#             */
/*   Updated: 2024/09/09 19:59:17 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "src/list/list.h"
#include "src/input_checker/input_checker.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("hello %d\n", is_valid_all(argc, argv));
    for (int i = 0; i < argc; i++){
        printf("str %s; is valid?%d;\n", argv[i], is_valid_string(argv[i]));
    }
    return (0);
}