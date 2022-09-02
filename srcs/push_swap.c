/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:46:46 by youngcho          #+#    #+#             */
/*   Updated: 2022/09/02 12:24:28 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_argv			argv_int;
	t_stack_info	stack_info;

	parsing_argument(&argv_int, argc, argv);
	init_stack_a_and_b(&stack_info, &argv_int);
	sort(&stack_info, argv_int.len);
	destroy_stack_a_and_b(&stack_info);
	return (0);
}
