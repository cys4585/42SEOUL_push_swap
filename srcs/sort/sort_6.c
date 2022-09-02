/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:43:13 by youngcho          #+#    #+#             */
/*   Updated: 2022/09/02 13:41:10 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack.h"
#include "stack_cmd.h"
#include "error.h"
#include <stdlib.h>

static void	merge(t_stack_info *stack_info, t_goal goal)
{
	int	target_size;
	int	temp_size;
	int	i;

	target_size = count_stack_size(goal.target);
	temp_size = count_stack_size(goal.temp);
	i = target_size + temp_size;
	while (i--)
	{
		if (temp_size == 0 || \
			(target_size && goal.target->bottom->data > goal.temp->top->data))
		{
			rr_target(stack_info, goal.target);
			target_size--;
		}
		else if (target_size == 0 || \
			(temp_size && goal.target->bottom->data < goal.temp->top->data))
		{
			p_target(stack_info, goal.target);
			temp_size--;
		}
	}
}

static void	sort_2(t_stack_info *stack_info, t_stack *target, t_order order)
{
	if (order == ASC && target->top->data > target->bottom->data)
		s_target(stack_info, target);
	else if (order == DESC && target->top->data < target->bottom->data)
		s_target(stack_info, target);
}

static void	sort_3(t_stack_info *stack_info, t_stack *target, t_order order)
{
	if (order == ASC)
	{
		if (target->top->data > target->top->prev->data \
		&& target->top->data > target->bottom->data)
			r_target(stack_info, target);
		else if (target->top->data < target->top->prev->data \
			&& target->top->prev->data > target->bottom->data)
			rr_target(stack_info, target);
		if (target->top->data > target->top->prev->data)
			s_target(stack_info, target);
	}
	else if (order == DESC)
	{
		if (target->top->data < target->top->prev->data \
		&& target->top->data < target->bottom->data)
			r_target(stack_info, target);
		else if (target->top->data > target->top->prev->data \
			&& target->top->prev->data < target->bottom->data)
			rr_target(stack_info, target);
		if (target->top->data < target->top->prev->data)
			s_target(stack_info, target);
	}
}

static void	sort_456(t_stack_info *stack_info, t_goal goal)
{
	int	i;

	i = 0;
	while (i++ < goal.size[0] - 3)
		pb(stack_info);
	sort_3(stack_info, goal.target, ASC);
	if (goal.size[0] - 3 == 3)
		sort_3(stack_info, goal.temp, DESC);
	else if (goal.size[0] - 3 == 2)
		sort_2(stack_info, goal.temp, DESC);
	merge(stack_info, goal);
}

void	sort_6(t_stack_info *stack_info, int n)
{
	t_goal	final_goal;

	final_goal.target = stack_info->a;
	final_goal.temp = stack_info->b;
	final_goal.size = malloc(sizeof(int) * 1);
	check_error(MALLOC, "sort", final_goal.size);
	final_goal.size[0] = n;
	final_goal.cnt = 1;
	if (n == 2)
		sort_2(stack_info, stack_info->a, ASC);
	else if (n == 3)
		sort_3(stack_info, stack_info->a, ASC);
	else if (4 <= n && n <= 6)
		sort_456(stack_info, final_goal);
	free(final_goal.size);
}
