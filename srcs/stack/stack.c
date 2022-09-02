/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:06:20 by youngcho          #+#    #+#             */
/*   Updated: 2022/09/02 12:24:16 by youngcho         ###   ########.fr       */
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
	t_node	*node;
	t_node	*next;

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

void	init_stack_a_and_b(t_stack_info *stack_info, t_argv *argv_int)
{
	int	i;

	stack_info->a = create_stack();
	stack_info->b = create_stack();
	i = 0;
	while (i < argv_int->len)
		push(stack_info->a, argv_int->argv[argv_int->len - 1 - i++]);
	free(argv_int->argv);
}

void	destroy_stack_a_and_b(t_stack_info *stack_info)
{
	if (stack_info->a->bottom)
		free_all_node(stack_info->a);
	if (stack_info->b->bottom)
		free_all_node(stack_info->b);
	free(stack_info->a);
	free(stack_info->b);
}

int	count_stack_size(t_stack *stack)
{
	t_node	*node;
	int		cnt;

	node = stack->top;
	cnt = 0;
	while (node)
	{
		cnt++;
		node = node->prev;
	}
	return (cnt);
}
