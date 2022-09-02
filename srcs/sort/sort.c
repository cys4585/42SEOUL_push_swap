/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:37:53 by youngcho          #+#    #+#             */
/*   Updated: 2022/09/02 19:48:38 by youngcho         ###   ########.fr       */
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
	printf("\n");
}

void	print_goal(t_goal *goal, t_stack_info * stack_info)
{
	if (goal->target == stack_info->a)
		printf("target:(A) %p | temp:(B) %p\n", goal->target, goal->temp);
	else
		printf("target:(B) %p | temp:(A) %p\n", goal->target, goal->temp);
	printf("cnt: %d\n", goal->cnt);
	int i = 0;
	printf("size: ");
	while (i < goal->cnt)
	{
		printf("%d ", goal->size[i]);
		i++;
	}
	printf("\n");
	i = 0;
	printf("order: ");
	while (i < goal->cnt)
	{
		if (goal->order[i] == ASC)
			printf("ASC ");
		else
			printf("DESC ");
		i++;
	}
	printf("\n############################################\n\n");
}

void	destroy_goal(t_goal *goal)
{
	free(goal->size);
	free(goal->order);
	free(goal);
}

void	ready_to_merge(t_stack_info *stack_info, t_goal *goal)
{
	int	size;
	int	i;

	i = 0;
	while (i < goal->cnt / 3)
	{
		size = goal->size[goal->cnt - 1 - i];
		while (size--)
			p_target(stack_info, goal->temp);
		i++;
	}
}

void	merge(t_stack_info *stack_info, t_goal *curr_goal)
{
	
}

void	divide_and_sort_and_merge(t_stack_info *stack_info, t_goal *curr_goal)
{
	t_goal	*child_goal;

	if (curr_goal->size[0] <= 3)
		first_sort(stack_info, curr_goal);
	else
	{
		child_goal = create_child_goal(curr_goal);
		
		print_goal(child_goal, stack_info);

		divide_and_sort_and_merge(stack_info, child_goal);
		
		ready_to_merge(stack_info, child_goal);
		merge(stack_info, curr_goal);
		
		print_stack(stack_info);
		print_goal(curr_goal, stack_info);
		
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
	printf("\nA: %p | B: %p\n", stack_info->a, stack_info->b);
	print_goal(final_goal, stack_info);
	divide_and_sort_and_merge(stack_info, final_goal);
	// print_stack(stack_info);
	destroy_goal(final_goal);
}
