/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:38:12 by youngcho          #+#    #+#             */
/*   Updated: 2022/09/03 16:56:22 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "stack.h"

typedef enum e_order {
	ASC,
	DESC
}	t_order;

typedef struct s_goal {
	t_stack	*target;
	t_stack	*temp;
	int		cnt;
	int		*sizes;
	t_order	*orders;
}	t_goal;

typedef struct s_count {
	int	target_bottom_cnt;
	int	temp_top_cnt;
	int	temp_bottom_cnt;
}	t_count;

void	sort_6(t_stack_info *stack_info, int n);
t_goal	*create_final_goal(t_stack_info *stack_info, int n);
t_goal	*create_child_goal(t_goal *parent_goal);
void	first_sort(t_stack_info *stack_info, t_goal *goal);
void	move_one(t_stack_info *stack_info, t_goal *goal, \
					int child_sizes[], int idx);

#endif