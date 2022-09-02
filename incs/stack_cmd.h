/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cmd.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:54:19 by youngcho          #+#    #+#             */
/*   Updated: 2022/09/02 11:05:24 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_CMD_H
# define STACK_CMD_H

# include "stack.h"

void	sa(t_stack_info *stack_info);
void	sb(t_stack_info *stack_info);
void	ss(t_stack_info *stack_info);
void	s_target(t_stack_info *stack_info, t_stack *target);

void	pa(t_stack_info *stack_info);
void	pb(t_stack_info *stack_info);
void	p_target(t_stack_info *stack_info, t_stack *target);

void	ra(t_stack_info *stack_info);
void	rb(t_stack_info *stack_info);
void	rr(t_stack_info *stack_info);
void	r_target(t_stack_info *stack_info, t_stack *target);

void	rra(t_stack_info *stack_info);
void	rrb(t_stack_info *stack_info);
void	rrr(t_stack_info *stack_info);
void	rr_target(t_stack_info *stack_info, t_stack *target);

#endif