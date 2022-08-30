/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:36:45 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/30 14:18:24 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef enum e_error {
	MALLOC,
	CUS_ARG
}	t_error;

void	custom_check_error(t_error err, char *str, int ret);
void	check_error(t_error err, char *str, void *ret);

#endif