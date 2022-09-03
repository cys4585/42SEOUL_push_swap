/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:37:53 by youngcho          #+#    #+#             */
/*   Updated: 2022/09/03 16:57:54 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "stack_cmd.h"
#include "sort.h"
#include "libft.h"
#include "error.h"
#include <stdlib.h>

static void	destroy_goal(t_goal *goal)
{
	free(goal->sizes);
	free(goal->orders);
	free(goal);
}

static void	ready_to_merge(
	t_stack_info *stack_info, t_goal *child_goal, t_goal *curr_goal
)
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
		size = child_goal->sizes[i] + \
			child_goal->sizes[curr_goal->cnt * 2 - 1 - i] + \
			child_goal->sizes[curr_goal->cnt * 3 - 1 - i];
		curr_goal->sizes[i] = size;
		i++;
	}
}

static void	merge(t_stack_info *stack_info, t_goal *goal, int child_sizes[])
{
	int	i;
	int	j;

	i = 0;
	while (i < goal->cnt)
	{
		j = 0;
		while (j < goal->sizes[i])
		{
			move_one(stack_info, goal, child_sizes, i);
			j++;
		}
		i++;
	}
	return ;
}

static void	divide_and_sort_and_merge(
	t_stack_info *stack_info, t_goal *curr_goal
)
{
	t_goal	*child_goal;

	if (curr_goal->sizes[0] <= 3)
		first_sort(stack_info, curr_goal);
	else
	{
		child_goal = create_child_goal(curr_goal);
		divide_and_sort_and_merge(stack_info, child_goal);
		ready_to_merge(stack_info, child_goal, curr_goal);
		merge(stack_info, curr_goal, child_goal->sizes);
		destroy_goal(child_goal);
	}
}

void	sort(t_stack_info *stack_info, int n)
{
	t_goal	*final_goal;

	if (n <= 6)
		sort_6(stack_info, n);
	final_goal = create_final_goal(stack_info, n);
	divide_and_sort_and_merge(stack_info, final_goal);
	destroy_goal(final_goal);
}
