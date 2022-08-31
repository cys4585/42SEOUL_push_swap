/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:36:35 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/31 12:15:32 by youngcho         ###   ########.fr       */
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

static void	custom_exit_with_stderr(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

void	check_error(t_error err, char *str, void *ret)
{
	if (err == MALLOC && ret == NULL)
		exit_with_perror(str);
}

void	custom_check_error(t_error err, char *str, int ret)
{
	if (err == CUS_ARG && ret == 0)
		custom_exit_with_stderr(str);
}
