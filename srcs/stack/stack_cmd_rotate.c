/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cmd_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:48:39 by youngcho          #+#    #+#             */
/*   Updated: 2022/09/02 16:10:45 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"
#include "libft.h"
#include <unistd.h>

void	ra(t_stack_info *stack_info)
{
	rotate(stack_info->a);
	// ft_putendl_fd("ra", STDOUT_FILENO);
}

void	rb(t_stack_info *stack_info)
{
	rotate(stack_info->b);
	// ft_putendl_fd("rb", STDOUT_FILENO);
}

void	rr(t_stack_info *stack_info)
{
	rotate(stack_info->a);
	rotate(stack_info->b);
	// ft_putendl_fd("rr", STDOUT_FILENO);
}

void	r_target(t_stack_info *stack_info, t_stack *target)
{
	if (target == stack_info->a)
		ra(stack_info);
	else
		rb(stack_info);
}
