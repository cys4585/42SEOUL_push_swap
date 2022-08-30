/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:46:46 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/30 17:01:16 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
int	main(int argc, char *argv[])
{
	t_argv	argv_int;
	t_stack	*a;
	t_stack	*b;

	parsing_argument(&argv_int, argc, argv);
	init_stack_a_and_b(&a, &b, &argv_int);
	return (0);
}
