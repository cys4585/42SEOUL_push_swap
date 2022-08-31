/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:56:42 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/31 14:22:09 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "error.h"
#include <stdlib.h>

void	swap(t_stack *stack)
{
	t_node	*top_node;
	t_node	*second_node;
	t_node	*third_node;

	if (stack->top == stack->bottom)
		return ;
	top_node = stack->top;
	second_node = top_node->prev;
	third_node = second_node->prev;
	stack->top = second_node;
	top_node->next = second_node;
	top_node->prev = third_node;
	second_node->next = NULL;
	second_node->prev = top_node;
	if (third_node)
		third_node->next = top_node;
	else
		stack->bottom = top_node;
	
}

void	push(t_stack *stack, int data)
{
	t_node	*new_node;
	t_node	*old_top;

	old_top = stack->top;
	new_node = (t_node *)malloc(sizeof(t_node));
	check_error(MALLOC, "push", new_node);
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = old_top;
	stack->top = new_node;
	if (old_top)
		old_top->next = new_node;
	else
		stack->bottom = new_node;
}

int	pop(t_stack *stack)
{
	t_node	*delete_node;
	t_node	*new_top;
	int		data;

	delete_node = stack->top;
	new_top = delete_node->prev;
	data = delete_node->data;
	free(delete_node);
	stack->top = new_top;
	if (new_top)
		new_top->next = NULL;
	else
		stack->bottom = NULL;
	return (data);
}

void	rotate(t_stack *stack)
{
	t_node	*old_top;
	t_node	*old_bottom;
	t_node	*new_top;
	t_node	*new_bottom;

	if (stack->top == stack->bottom)
		return ;
	old_top = stack->top;
	old_bottom = stack->bottom;
	new_top = old_top->prev;
	new_bottom = old_top;
	stack->top = new_top;
	stack->bottom = new_bottom;
	new_bottom->next = old_bottom;
	new_bottom->prev = NULL;
	old_bottom->prev = new_bottom;
	new_top->next = NULL;
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*old_top;
	t_node	*old_bottom;
	t_node	*new_top;
	t_node	*new_bottom;

	if (stack->top == stack->bottom)
		return ;
	old_top = stack->top;
	old_bottom = stack->bottom;
	new_top = old_bottom;
	new_bottom = old_bottom->next;
	stack->top = new_top;
	stack->bottom = new_bottom;
	new_top->next = NULL;
	new_top->prev = old_top;
	old_top->next = new_top;
	new_bottom->prev = NULL;
}
