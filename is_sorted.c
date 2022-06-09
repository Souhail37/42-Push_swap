/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:12:44 by sismaili          #+#    #+#             */
/*   Updated: 2022/04/27 15:55:03 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_a(t_stack *new, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		new[j].value = ft_atoi(av[i]);
		new[j].pos = -1;
		i++;
		j++;
	}
	new[j].pos = -1;
}

void	ft_init_b(t_stack *new, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		new[i].value = 0;
		i++;
	}
}

int	ft_is_sorted(t_stack *var, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (var[i].value < var[i - 1].value)
			return (0);
		else
			i++;
	}
	return (1);
}

int	ft_isthere(t_list *var, int size)
{
	int	i;

	i = 0;
	while (i < var->st_a_len)
	{
		if (var->stack_a[i].pos < size)
			return (1);
		i++;
	}
	return (0);
}

int	validarg(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j] == ' ')
			j++;
		if (av[i][j] == 0)
		{
			write(2, "ERROR\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}
