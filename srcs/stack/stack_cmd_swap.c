/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cmd_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:40:30 by youngcho          #+#    #+#             */
/*   Updated: 2022/09/02 16:10:49 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"
#include "libft.h"
#include <unistd.h>

void	sa(t_stack_info *stack_info)
{
	swap(stack_info->a);
	// ft_putendl_fd("sa", STDOUT_FILENO);
}

void	sb(t_stack_info *stack_info)
{
	swap(stack_info->b);
	// ft_putendl_fd("sb", STDOUT_FILENO);
}

void	ss(t_stack_info *stack_info)
{
	swap(stack_info->a);
	swap(stack_info->b);
	// ft_putendl_fd("ss", STDOUT_FILENO);
}

void	s_target(t_stack_info *stack_info, t_stack *target)
{
	if (target == stack_info->a)
		sa(stack_info);
	else
		sb(stack_info);
}
