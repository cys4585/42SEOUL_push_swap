/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:52:40 by youngcho          #+#    #+#             */
/*   Updated: 2022/09/03 17:04:26 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "sort.h"
#include "stack_cmd.h"

static t_node	*compare_2_node(t_node *node1, t_node *node2, t_order order)
{
	if (order == ASC)
	{
		if (node1->data > node2->data)
			return (node1);
		else
			return (node2);
	}
	else
	{
		if (node1->data < node2->data)
			return (node1);
		else
			return (node2);
	}
}

static t_node	*compare_3_node(t_goal *goal, t_order order)
{
	t_node	*node;

	if (order == ASC)
	{
		if (goal->temp->top->data > goal->temp->bottom->data)
			node = goal->temp->top;
		else
			node = goal->temp->bottom;
		if (goal->target->bottom->data > node->data)
			node = goal->target->bottom;
	}
	else
	{
		if (goal->temp->top->data < goal->temp->bottom->data)
			node = goal->temp->top;
		else
			node = goal->temp->bottom;
		if (goal->target->bottom->data < node->data)
			node = goal->target->bottom;
	}
	return (node);
}

static t_node	*get_node_to_move(t_goal *goal, int child_sizes[], int idx)
{
	t_order	order;

	order = goal->orders[idx];
	if (child_sizes[idx] == 0 && child_sizes[goal->cnt * 2 - 1 - idx] == 0)
		return (goal->target->bottom);
	else if (child_sizes[idx] == 0 && child_sizes[goal->cnt * 3 - 1 - idx] == 0)
		return (goal->temp->top);
	else if (child_sizes[goal->cnt * 2 - 1 - idx] == 0 \
				&& child_sizes[goal->cnt * 3 - 1 - idx] == 0)
		return (goal->temp->bottom);
	else if (child_sizes[idx] == 0)
		return (compare_2_node(goal->temp->top, goal->target->bottom, order));
	else if (child_sizes[goal->cnt * 2 - 1 - idx] == 0)
		return (compare_2_node(goal->target->bottom, \
								goal->temp->bottom, order));
	else if (child_sizes[goal->cnt * 3 - 1 - idx] == 0)
		return (compare_2_node(goal->temp->bottom, goal->temp->top, order));
	else
		return (compare_3_node(goal, order));
}

void	move_one(
	t_stack_info *stack_info, t_goal *goal, int child_sizes[], int idx
)
{
	t_node	*node;

	node = get_node_to_move(goal, child_sizes, idx);
	if (node == goal->target->bottom)
	{
		rr_target(stack_info, goal->target);
		child_sizes[goal->cnt * 3 - 1 - idx]--;
	}
	else if (node == goal->temp->top)
	{
		p_target(stack_info, goal->target);
		if (child_sizes[goal->cnt * 2 - 1 - idx])
			child_sizes[goal->cnt * 2 - 1 - idx]--;
		else
			child_sizes[idx]--;
	}
	else if (node == goal->temp->bottom)
	{
		rr_target(stack_info, goal->temp);
		p_target(stack_info, goal->target);
		child_sizes[idx]--;
	}
}
