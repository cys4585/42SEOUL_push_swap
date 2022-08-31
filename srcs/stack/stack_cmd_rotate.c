/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cmd_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:48:39 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/31 13:57:51 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"
#include "libft.h"
#include <unistd.h>

void	ra(t_stack *a)
{
	rotate(a);
	ft_putendl_fd("ra", STDOUT_FILENO);
}

void	rb(t_stack *b)
{
	rotate(b);
	ft_putendl_fd("rb", STDOUT_FILENO);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", STDOUT_FILENO);
}
