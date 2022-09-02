/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_goal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:44:38 by youngcho          #+#    #+#             */
/*   Updated: 2022/09/02 18:15:52 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack.h"
#include "error.h"
#include <stdlib.h>

static void	compute_goal_size(t_goal *parent_goal, t_goal *goal)
{
	int	remainder;
	int	i;
	int	j;

	i = 0;
	while (i < parent_goal->cnt)
	{
		j = 0;
		while (j < 3)
		{
			goal->size[i * 3 + j] = parent_goal->size[i] / 3;
			j++;
		}
		remainder = parent_goal->size[i] % 3;
		if (remainder)
		{
			goal->size[i * 3]++;
			if (remainder == 2)
				goal->size[i * 3 + 1]++;
		}
		i++;
	}
}

static void	insert_order(t_order *dest, t_order *src, int len, int is_forward)
{
	t_order	order;
	int		j;

	j = 0;
	while (j < len)
	{
		if (is_forward == 1)
			order = src[j];
		else
		{
			order = src[len - 1 - j];
			if (order == ASC)
				order = DESC;
			else
				order = ASC;
		}
		dest[j] = order;
		j++;
	}
}

static void	compute_goal_order(t_goal *parent_goal, t_goal *goal)
{
	int		len;
	int		i;

	len = parent_goal->cnt;
	i = 0;
	while (i < 3)
	{
		if (i == 0)
			insert_order(goal->order + (i * len), parent_goal->order, len, 1);
		else
			insert_order(goal->order + (i * len), parent_goal->order, len, 0);
		i++;
	}
}

t_goal	*create_child_goal(t_goal *parent_goal)
{
	t_goal	*goal;

	goal = malloc(sizeof(t_goal) * 1);
	check_error(MALLOC, "set_goal", goal);
	goal->target = parent_goal->temp;
	goal->temp = parent_goal->target;
	goal->cnt = parent_goal->cnt * 3;
	goal->size = malloc(sizeof(int) * goal->cnt);
	check_error(MALLOC, "set_goal", goal->size);
	compute_goal_size(parent_goal, goal);
	goal->order = malloc(sizeof(t_order) * goal->cnt);
	check_error(MALLOC, "set_goal", goal->order);
	compute_goal_order(parent_goal, goal);
	return (goal);
}

t_goal	*create_final_goal(t_stack_info *stack_info, int n)
{
	t_goal	*goal;

	goal = malloc(sizeof(t_goal) * 1);
	check_error(MALLOC, "set_goal", goal);
	goal->target = stack_info->a;
	goal->temp = stack_info->b;
	goal->size = malloc(sizeof(int) * 1);
	check_error(MALLOC, "set_goal", goal->size);
	goal->size[0] = n;
	goal->cnt = 1;
	goal->order = malloc(sizeof(t_order) * 1);
	check_error(MALLOC, "set_goal", goal->order);
	goal->order[0] = ASC;
	return (goal);
}
