/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:31:07 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/30 16:18:33 by youngcho         ###   ########.fr       */
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

void	swap(t_stack *stack);
void	push(t_stack *stack, int data);
int		pop(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

#endif