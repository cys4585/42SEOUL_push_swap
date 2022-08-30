/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_argument_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:21:41 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/30 14:47:47 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_number(char *str)
{
	int	i;

	if (str[0] == '-' || str[0] == '+')
	{
		if (str[1] == '\0')
			return (0);
		i = 1;
	}
	else
		i = 0;
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	is_unique(int argv[], int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		if (argv[i] == argv[idx])
			return (0);
		i++;
	}
	return (1);
}
