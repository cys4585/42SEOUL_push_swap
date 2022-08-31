/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:37:53 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/31 15:57:50 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "stack_cmd.h"

void	set_size(int size[], int n)
{
	int	quotient;
	int	remainder;
	quotient = n / 3;
	remainder = n % 3;
	size[0] = quotient + remainder;
	if (remainder == 1)
		size[1] = quotient;
	else
		size[1] = quotient + remainder;
	size[2] = quotient;
}

void	divide(t_stack *a, t_stack *b, int cnt)
{
	while (cnt--)
		pb(a, b);
	// sort();
}

t_node	*find_max(t_stack *a, t_stack *b, int size[])
{
	t_node	*max_node;
	int		i;


	i = 0;
	while (i < 3)
	{
		if (size[i])
			break ;
		i++;
	}
	if (i == 0)
	{
		max_node = a->bottom;
		if (max_node->data < b->top->data)
			max_node = b->top;
		if (max_node->data < b->bottom->data)
			max_node = b->bottom;
	}
	else if (i == 1)
		if (b->top->data < b->bottom->data)
			max_node = b->bottom;
		else
			max_node = b->top;
	else
		max_node = b->bottom;
	return max_node;
}

void	merge(t_stack *a, t_stack *b, int size[])
{
	t_node	*max_node;
	int		loop_cnt;

	loop_cnt = size[0] + size[1] + size[2];
	while (loop_cnt--)
	{
		max_node = find_max(a, b, size);
		if (max_node == a->bottom)
		{
			size[0]--;
			rra(a);
		}
		else if (max_node == b->top)
		{
			size[1]--;
			pa(a, b);
		}
		else
		{
			size[2]--;
			rrb(b);
			pa(a, b);
		}
	}
}

void	merge_sort(t_stack *a, t_stack *b, int n)
{
	int size[3];

	if (n == 2)
		sa(a);
	else
	{
		set_size(size, n);
		divide(a, b, size[2]);
		divide(a, b, size[1]);
		merge(a, b, size);
	}
}