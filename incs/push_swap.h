/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:04:10 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/30 14:19:01 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "parsing_argument.h"
# include "stack.h"

void	parsing_argument(t_argv *argv_int, int argc, char *argv[]);
void	init_stack_a_and_b(t_stack **a, t_stack **b, t_argv *argv_int);

#endif