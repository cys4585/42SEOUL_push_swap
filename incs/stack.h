/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:31:07 by youngcho          #+#    #+#             */
/*   Updated: 2022/09/02 12:07:50 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_node {
	struct s_node	*next;
	int				data;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack {
	t_node	*top;
	t_node	*bottom;
}	t_stack;

typedef struct s_stack_info {
	t_stack	*a;
	t_stack	*b;
}	t_stack_info;

int	count_stack_size(t_stack *stack);

#endif