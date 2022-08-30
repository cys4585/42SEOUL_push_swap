/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:06:20 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/30 15:22:23 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "parsing_argument.h"
#include "error.h"
#include <stdlib.h>

static t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->top = NULL;
	stack->bottom = NULL;
	check_error(MALLOC, "create_stack", stack);
	return (stack);
}

void	init_stack_a_and_b(t_stack **a, t_stack **b, t_argv *argv_int)
{
	*a = create_stack();
	*b = create_stack();
	while (argv_int->len--)
		push(*a, argv_int->argv[argv_int->len]);
	free(argv_int->argv);
}
