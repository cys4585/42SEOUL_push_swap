/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:06:20 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/29 19:02:52 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "error.h"
#include <stdlib.h>

t_stack	*create_node(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	check_error(MALLOC, "create_node", stack);
	return (stack);
}
