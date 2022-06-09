/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 01:46:52 by sismaili          #+#    #+#             */
/*   Updated: 2022/04/27 16:14:02 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(char **sep, int i)
{
	int	j;

	while (sep[i])
	{
		j = 0;
		while (sep[i][j])
		{
			if (sep[i][j] == '+' || sep[i][j] == '-')
				j++;
			if (sep[i][j] < 48 || sep[i][j] > 57)
			{
				write(2, "ERROR\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_double(char **sep, int i)
{
	int	j;

	while (sep[i])
	{
		j = i + 1;
		while (sep[j])
		{
			if (ft_atoi(sep[i]) == ft_atoi(sep[j]))
			{
				write(2, "ERROR\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_int(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (ft_atol(av[i]) > 2147483647 || ft_atol(av[i]) < -2147483648)
		{
			write(2, "ERROR\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}
