/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cmd_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:40:30 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/31 13:56:23 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"
#include "libft.h"
#include <unistd.h>

void	sa(t_stack *a)
{
	swap(a);
	ft_putendl_fd("sa", STDOUT_FILENO);
}

void	sb(t_stack *b)
{
	swap(b);
	ft_putendl_fd("sb", STDOUT_FILENO);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_putendl_fd("ss", STDOUT_FILENO);
	
}
