/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:06:20 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/30 14:40:18 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "parsing_argument.h"
#include "error.h"
#include <stdlib.h>

void	push(t_stack *stack, int value)
{
	t_node	*new_node;
	t_node	*old_top;

	old_top = stack->top;
	new_node = (t_node *)malloc(sizeof(t_node));
	check_error(MALLOC, "push", new_node);
	new_node->data = value;
	new_node->next = NULL;
	new_node->prev = old_top;
	stack->top = new_node;
	if (old_top)
		old_top->next = new_node;
	else
		stack->bottom = new_node;
}

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
