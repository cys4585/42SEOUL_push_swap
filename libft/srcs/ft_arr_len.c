/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:01:00 by youngcho          #+#    #+#             */
/*   Updated: 2022/09/03 16:50:44 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strarr_len(char *strarr[])
{
	int	i;

	i = 0;
	while (strarr[i])
		i++;
	return (i);
}

int	ft_intarr_len(int *intarr[])
{
	int	i;

	i = 0;
	while (intarr[i])
		i++;
	return (i);
}
