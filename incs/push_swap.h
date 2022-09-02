/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:04:10 by youngcho          #+#    #+#             */
/*   Updated: 2022/09/02 12:23:23 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "parsing_argument.h"
# include "stack.h"

void	parsing_argument(t_argv *argv_int, int argc, char *argv[]);
void	init_stack_a_and_b(t_stack_info *stack_info, t_argv *argv_int);
void	destroy_stack_a_and_b(t_stack_info *stack_info);
void	sort(t_stack_info *stack_info, int n);

#endif