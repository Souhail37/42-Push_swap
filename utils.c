/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:59:16 by sismaili          #+#    #+#             */
/*   Updated: 2022/09/06 12:27:26 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushswap(t_list var, int ac)
{
	if (ft_is_sorted(var.stack_a, ac))
		return ;
	if (ac == 2)
	{
		if (var.stack_a[0].value > var.stack_a[1].value)
			swap_a(var);
	}
	if (ac == 3)
		sort_3_a(var);
	if (ac >= 4 && ac <= 10)
		sort_less_10(&var, ac);
	if (ac > 10 && ac <= 100)
		just_sort(&var, 5, ac);
	if (ac > 100 && ac <= 500)
		just_sort(&var, 10, ac);
}

int	ft_min(t_stack *var, int size)
{
	int	i;
	int	min;

	i = 0;
	min = var[i].value;
	while (i < size)
	{
		if (min > var[i].value)
			min = var[i].value;
		i++;
	}
	return (min);
}

int	ft_max(t_stack *var, int size, int *pos)
{
	int	i;
	int	max;

	i = 0;
	max = var[i].value;
	while (i < size)
	{
		if (max < var[i].value)
		{
			max = var[i].value;
			*pos = i;
		}
		i++;
	}
	return (max);
}

int	ft_second_max(t_stack *var, int size, int *pos, int max)
{
	int	i;
	int	second_max;

	i = 0;
	second_max = var[i].value;
	while (i < size)
	{
		if (second_max < var[i].value && var[i].value != max)
		{
			second_max = var[i].value;
			*pos = i;
		}
		i++;
	}
	return (second_max);
}

void	ft_done(t_list var, char **spl, int j)
{
	ft_init_a(var.stack_a, spl);
	ft_init_b(var.stack_b, j);
	ft_pushswap(var, j);
}
