/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:37:53 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/31 14:03:51 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "stack_cmd.h"

void	sort(t_stack *a, t_stack *b, int n)
{
	int size;
	
	if (n == 2)
		sa(a);
	else
	{
		size = n % 3;
		size = b->top->data;
	}
}