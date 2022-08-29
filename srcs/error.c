/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:36:35 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/29 19:03:06 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void	exit_with_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	check_error(t_error err, char *str, void *ret)
{
	if (err == MALLOC && ret == NULL)
		exit_with_perror(str);
}
