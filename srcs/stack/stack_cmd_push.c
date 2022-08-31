/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cmd_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:47:27 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/31 12:01:05 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"
#include <stddef.h>

void	pa(t_stack *a)
{
	if (a->top == NULL)
		return ;
	push(a, pop(a));
}

void	pb(t_stack *b)
{
	if (a->top == NULL)
		return ;
	push(b, pop(b));
}