/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cmd_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:50:10 by youngcho          #+#    #+#             */
/*   Updated: 2022/09/03 16:44:52 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"
#include "libft.h"
#include <unistd.h>

void	rra(t_stack_info *stack_info)
{
	reverse_rotate(stack_info->a);
	ft_putendl_fd("rra", STDOUT_FILENO);
}

void	rrb(t_stack_info *stack_info)
{
	reverse_rotate(stack_info->b);
	ft_putendl_fd("rrb", STDOUT_FILENO);
}

void	rrr(t_stack_info *stack_info)
{
	reverse_rotate(stack_info->a);
	reverse_rotate(stack_info->b);
	ft_putendl_fd("rrr", STDOUT_FILENO);
}

void	rr_target(t_stack_info *stack_info, t_stack *target)
{
	if (target == stack_info->a)
		rra(stack_info);
	else
		rrb(stack_info);
}
