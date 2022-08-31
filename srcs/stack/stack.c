/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:06:20 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/31 15:38:13 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "stack_utils.h"
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

static void	free_all_node(t_stack *stack)
{
	t_node *node;
	t_node *next;

	node = stack->bottom;
	next = node->next;
	while (node)
	{
		free(node);
		node = next;
		if (node)
			next = node->next;
	}
}

void	init_stack_a_and_b(t_stack **a_p, t_stack **b_p, t_argv *argv_int)
{
	int	i;
	
	*a_p = create_stack();
	*b_p = create_stack();
	i = 0;
	while (i < argv_int->len)
		push(*a_p, argv_int->argv[argv_int->len - 1 - i++]);
	free(argv_int->argv);
}

void	destroy_stack_a_and_b(t_stack *a, t_stack *b)
{
	if (a->bottom)
		free_all_node(a);
	if (b->bottom)
		free_all_node(b);
	free(a);
	free(b);
}