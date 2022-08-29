/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:31:07 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/29 19:03:57 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack	t_stack;
struct s_stack {
	int		value;
	t_stack	*top;
	t_stack	*next;
	t_stack	*prev;
	t_stack	*bottom;
};

t_stack	*create_node(void);

#endif