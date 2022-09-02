/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:29:57 by youngcho          #+#    #+#             */
/*   Updated: 2022/09/02 19:34:10 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "stack_cmd.h"
#include "sort.h"

static void	ready_for_first_sort(t_stack_info *stack_info, t_goal *goal)
{
	int		size;
	int		i;

	if (goal->target == stack_info->b)
		return ;
	size = 0;
	i = 0;
	while (i < goal->cnt)
		size += goal->size[i++];
	while (size--)
		pb(stack_info);
}

static void	move_2(t_stack_info *stack_info, t_goal *goal, t_order order)
{
	if (order == ASC)
	{
		if (goal->temp->top->data > goal->temp->top->prev->data)
			p_target(stack_info, goal->target);
		else
		{
			s_target(stack_info, goal->temp);
			p_target(stack_info, goal->target);
		}
		p_target(stack_info, goal->target);
	}
	else
	{
		if (goal->temp->top->data < goal->temp->top->prev->data)
			p_target(stack_info, goal->target);
		else
		{
			s_target(stack_info, goal->temp);
			p_target(stack_info, goal->target);
		}
		p_target(stack_info, goal->target);
	}
}

static t_node	*get_first_node(t_goal *goal, t_order order)
{
	t_node	*node;

	if (order == ASC)
	{
		if (goal->temp->top->data > goal->temp->top->prev->data)
			node = goal->temp->top;
		else
			node = goal->temp->top->prev;
		if (goal->temp->top->prev->prev->data > node->data)
			node = goal->temp->top->prev->prev;
	}
	else
	{
		if (goal->temp->top->data < goal->temp->top->prev->data)
			node = goal->temp->top;
		else
			node = goal->temp->top->prev;
		if (goal->temp->top->prev->prev->data < node->data)
			node = goal->temp->top->prev->prev;
	}
	return (node);
}

static void	move_3(t_stack_info *stack_info, t_goal *goal, t_order order)
{
	t_node	*node;

	node = get_first_node(goal, order);
	if (node == goal->temp->top)
		p_target(stack_info, goal->target);
	else if (node == goal->temp->top->prev)
	{
		s_target(stack_info, goal->temp);
		p_target(stack_info, goal->target);
	}
	else
	{
		r_target(stack_info, goal->temp);
		s_target(stack_info, goal->temp);
		p_target(stack_info, goal->target);
		rr_target(stack_info, goal->temp);
	}
	move_2(stack_info, goal, order);
}

void	first_sort(t_stack_info *stack_info, t_goal *goal)
{
	int	size;
	int	i;

	i = 0;
	ready_for_first_sort(stack_info, goal);
	while (i < goal->cnt)
	{
		size = goal->size[i];
		if (size == 3)
			move_3(stack_info, goal, goal->order[i]);
		else if (size == 2)
			move_2(stack_info, goal, goal->order[i]);
		else
			p_target(stack_info, goal->target);
		i++;
	}
}
