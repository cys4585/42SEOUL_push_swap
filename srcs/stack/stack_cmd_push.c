/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cmd_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:47:27 by youngcho          #+#    #+#             */
/*   Updated: 2022/09/02 16:10:31 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"
#include "libft.h"
#include <stddef.h>
#include <unistd.h>

void	pa(t_stack_info *stack_info)
{
	if (stack_info->b->top == NULL)
		return ;
	push(stack_info->a, pop(stack_info->b));
	// ft_putendl_fd("pa", STDOUT_FILENO);
}

void	pb(t_stack_info *stack_info)
{
	if (stack_info->a->top == NULL)
		return ;
	push(stack_info->b, pop(stack_info->a));
	// ft_putendl_fd("pb", STDOUT_FILENO);
}

void	p_target(t_stack_info *stack_info, t_stack *target)
{
	if (target == stack_info->a)
		pa(stack_info);
	else
		pb(stack_info);
}
