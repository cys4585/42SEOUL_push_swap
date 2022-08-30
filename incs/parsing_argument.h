/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_argument.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:00:39 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/30 17:02:12 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_ARGUMENT_H
# define PARSING_ARGUMENT_H

typedef struct s_argv
{
	int	*argv;
	int	len;
}	t_argv;

int	is_number(char *str);
int	is_unique(int argv[], int idx);
int	is_already_sorted(t_argv *argv_int);

#endif