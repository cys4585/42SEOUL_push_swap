/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:46:46 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/30 19:00:23 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_argv	argv_int;
	t_stack	*a;
	t_stack	*b;

	parsing_argument(&argv_int, argc, argv);
	init_stack_a_and_b(&a, &b, &argv_int);
	// 스택에 요소가 없을 때 pop을 하면 segmentation fault
	// pa pb 할 때 예외처리 해줘야 함
	
	return (0);
}
