/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:37:53 by youngcho          #+#    #+#             */
/*   Updated: 2022/09/03 16:42:17 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "stack_cmd.h"
#include "sort.h"
#include "libft.h"
#include "error.h"
#include <stdlib.h>

#include <stdio.h>
void	print_stack(t_stack_info *stack_info)
{
	t_node *node;

	printf("\n###########################################################\n");
	printf("A: %p | B: %p\n", stack_info->a, stack_info->b);
	node = stack_info->a->top;
	printf("Stack A\n	");
	while (node)
	{
		printf("%d ", node->data);
		node = node->prev;
	}
	printf("\n");
	printf("Stack B\n	");
	node = stack_info->b->top;
	while (node)
	{
		printf("%d ", node->data);
		node = node->prev;
	}
	printf("\n###########################################################\n\n");
}

void	print_goal(t_goal *goal, t_stack_info * stack_info)
{
	printf("\n############################################\n");
	if (goal->target == stack_info->a)
		printf("target:(A) %p | temp:(B) %p\n", goal->target, goal->temp);
	else
		printf("target:(B) %p | temp:(A) %p\n", goal->target, goal->temp);
	printf("cnt: %d\n", goal->cnt);
	int i = 0;
	printf("size: ");
	while (i < goal->cnt)
	{
		printf("%d ", goal->sizes[i]);
		i++;
	}
	printf("\n");
	i = 0;
	printf("order: ");
	while (i < goal->cnt)
	{
		if (goal->orders[i] == ASC)
			printf("ASC ");
		else
			printf("DESC ");
		i++;
	}
	printf("\n############################################\n\n");
}

void	destroy_goal(t_goal *goal)
{
	free(goal->sizes);
	free(goal->orders);
	free(goal);
}

void	ready_to_merge(t_stack_info *stack_info, t_goal *child_goal, t_goal *curr_goal)
{
	int	size;
	int	i;

	i = 0;
	while (i < child_goal->cnt / 3)
	{
		size = child_goal->sizes[child_goal->cnt - 1 - i];
		while (size--)
			p_target(stack_info, child_goal->temp);
		i++;
	}
	i = 0;
	while (i < curr_goal->cnt)
	{
		size = child_goal->sizes[i] + 
			child_goal->sizes[curr_goal->cnt * 2 - 1 - i] + \
			child_goal->sizes[curr_goal->cnt * 3 - 1 - i];
		curr_goal->sizes[i] = size;
		i++;
	}
}

t_node	*compare_2_node(t_node *node1, t_node *node2, t_order order)
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

t_node	*compare_3_node(t_goal *goal, t_order order)
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

t_node	*get_node_to_move(t_goal *goal, int child_sizes[], int idx)
{
	t_order order;
	
	order = goal->orders[idx];
	if (child_sizes[idx] == 0 && child_sizes[goal->cnt * 2 - 1 - idx] == 0)
		return (goal->target->bottom);
	else if (child_sizes[idx] == 0 && child_sizes[goal->cnt * 3 - 1 - idx] == 0)
		return (goal->temp->top);
	else if (child_sizes[goal->cnt * 2 - 1 - idx] == 0 && child_sizes[goal->cnt * 3 - 1 - idx] == 0)
		return (goal->temp->bottom);
	else if (child_sizes[idx] == 0)
		return (compare_2_node(goal->temp->top, goal->target->bottom, order));
	else if (child_sizes[goal->cnt * 2 - 1 - idx] == 0)
		return (compare_2_node(goal->target->bottom, goal->temp->bottom, order));		
	else if (child_sizes[goal->cnt * 3 - 1 - idx] == 0)
		return (compare_2_node(goal->temp->bottom, goal->temp->top, order));		
	else
		return (compare_3_node(goal, order));
}

void	move_one(t_stack_info *stack_info, t_goal *goal, int child_sizes[], int idx)
{
	t_node	*node;

	node = get_node_to_move(goal, child_sizes, idx);
	if (node == goal->target->bottom)
	{
		// printf("target bottom\n");
		rr_target(stack_info, goal->target);
		child_sizes[goal->cnt * 3 - 1 - idx]--;
	}
	else if (goal->temp->top == goal->temp->bottom)
	{
		// printf("temp top or bottom\n");
		p_target(stack_info, goal->target);
		if (child_sizes[goal->cnt * 2 - 1 - idx])
			child_sizes[goal->cnt * 2 - 1 - idx]--;
		else
			child_sizes[idx]--;
	}
	else if (node == goal->temp->top)
	{
		// printf("temp top\n");
		p_target(stack_info, goal->target);
		child_sizes[goal->cnt * 2 - 1 - idx]--;
	}
	else if (node == goal->temp->bottom)
	{
		// printf("temp bottom\n");
		rr_target(stack_info, goal->temp);
		p_target(stack_info, goal->target);
		child_sizes[idx]--;
	}
	// int	i = 0;
	// printf("	");
	// while (i < goal->cnt * 3)
	// {
	// 	printf("%d ", child_sizes[i]);
	// 	i++;
	// }
	// printf("\n");
}

void	merge(t_stack_info *stack_info, t_goal *goal, int child_sizes[])
{
	int	i;
	int	j;

	i = 0;
	while (i < goal->cnt)
	{
		j = 0;
		while (j < goal->sizes[i])
		{
			// printf("	%d | %d\n", i, j);
			// if (goal->orders[i] == ASC)
				// printf("	ASC\n");
			// else
				// printf("	DESC\n");
			move_one(stack_info, goal, child_sizes, i);
			// print_stack(stack_info);
			j++;
		}
		i++;
	}
	return ;
}

void	divide_and_sort_and_merge(t_stack_info *stack_info, t_goal *curr_goal)
{
	t_goal	*child_goal;

	if (curr_goal->sizes[0] <= 3)
		first_sort(stack_info, curr_goal);
	else
	{
		child_goal = create_child_goal(curr_goal);
		
		// print_goal(child_goal, stack_info);

		divide_and_sort_and_merge(stack_info, child_goal);
		
		ready_to_merge(stack_info, child_goal, curr_goal);
		// print_stack(stack_info);
		// print_goal(curr_goal, stack_info);
		merge(stack_info, curr_goal, child_goal->sizes);
		
		destroy_goal(child_goal);
	}
}

void	sort(t_stack_info *stack_info, int n)
{
	t_goal *final_goal;

	// print_stack(stack_info);
	if (n <= 6)
		sort_6(stack_info, n);
	final_goal = create_final_goal(stack_info, n);
	// print_stack(stack_info);
	// print_goal(final_goal, stack_info);
	divide_and_sort_and_merge(stack_info, final_goal);
	// print_stack(stack_info);
	destroy_goal(final_goal);
}
