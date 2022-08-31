/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cmd_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:47:27 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/31 13:57:17 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"
#include "libft.h"
#include <stddef.h>
#include <unistd.h>

void	pa(t_stack *a, t_stack *b)
{
	if (b->top == NULL)
		return ;
	push(a, pop(b));
	ft_putendl_fd("pa", STDOUT_FILENO);
	

}

void	pb(t_stack *b, t_stack *a)
{
	if (a->top == NULL)
		return ;
	push(b, pop(a));
	ft_putendl_fd("pb", STDOUT_FILENO);
}
