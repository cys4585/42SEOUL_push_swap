/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:46:46 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/31 15:38:53 by youngcho         ###   ########.fr       */
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
	// 일단 10개 미만의 수 정렬 만들어보자
	merge_sort(a, b, argv_int.len);
	destroy_stack_a_and_b(a, b);
	return (0);
}
