/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_argument.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:00:22 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/30 14:30:30 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_argument.h"
#include "libft.h"
#include "error.h"
#include <stdlib.h>

static void	strarr_to_intarr(t_argv *argv_int, int len, char *strarr[])
{
	int	i;

	argv_int->len = len;
	argv_int->argv = malloc(sizeof(int) * len);
	check_error(MALLOC, "strarr_to_intarr", argv_int->argv);
	i = 0;
	while (strarr[i])
	{
		custom_check_error(CUS_ARG, "Error", is_number(strarr[i]));
		argv_int->argv[i] = ft_atoi(strarr[i]);
		custom_check_error(CUS_ARG, "Error", is_unique(argv_int->argv, i));
		i++;
	}
}

static void	parsing_case_string(t_argv *argv_int, char *argv[])
{
	char	**arg_arr;
	int		len;

	arg_arr = ft_split(argv[1], ' ');
	len = ft_strarr_len(arg_arr);
	if (len == 1)
	{
		custom_check_error(CUS_ARG, "Error", is_number(arg_arr[0]));
		ft_array_free(arg_arr);
		exit(EXIT_SUCCESS);
	}
	strarr_to_intarr(argv_int, len, arg_arr);
}

static void	parsing_case_array(t_argv *argv_int, int argc, char *argv[])
{
	strarr_to_intarr(argv_int, argc - 1, argv + 1);
}

void	parsing_argument(t_argv *argv_int, int argc, char *argv[])
{
	if (argc == 1)
		exit(EXIT_SUCCESS);
	else if (argc == 2)
		parsing_case_string(argv_int, argv);
	else
		parsing_case_array(argv_int, argc, argv);
}
