/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_argument.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:00:39 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/29 18:55:21 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_ARGUMENT_H
# define PARSING_ARGUMENT_H

typedef struct s_argv
{
	int	*argv;
	int	len;
}	t_argv;

void	parsing_argument(t_argv *argv_int, int argc, char *argv[]);

#endif