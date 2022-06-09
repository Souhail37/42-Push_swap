/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_to_10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:14:42 by sismaili          #+#    #+#             */
/*   Updated: 2022/04/25 16:55:25 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_a(t_list var)
{
	int	j;

	j = 0;
	if (var.stack_a[j].value > var.stack_a[j + 1].value
		&& var.stack_a[j].value < var.stack_a[j + 2].value)
		swap_a(var);
	else if (var.stack_a[j].value > var.stack_a[j + 1].value
		&& var.stack_a[j + 1].value < var.stack_a[j + 2].value)
		rot_a(var);
	else if (var.stack_a[j].value < var.stack_a[j + 1].value
		&& var.stack_a[j].value > var.stack_a[j + 2].value)
		rev_rot_a(var);
	else if (var.stack_a[j].value > var.stack_a[j + 1].value
		&& var.stack_a[j + 1].value > var.stack_a[j + 2].value)
	{
		swap_a(var);
		rev_rot_a(var);
	}
	else if (var.stack_a[j].value < var.stack_a[j + 1].value
		&& var.stack_a[j].value < var.stack_a[j + 2].value)
	{
		swap_a(var);
		rot_a(var);
	}
}

void	ft_top_a(t_list *var, int min, int i, int ac)
{
	if (var->stack_a[1].value == min)
	{
		swap_a(*var);
		push_b(var, ac);
		return ;
	}
	while (var->stack_a[0].value != min)
	{
		if (i >= var->st_a_len / 2)
			rev_rot_a(*var);
		else
			rot_a(*var);
		if (var->stack_a[0].value == min)
		{
			push_b(var, ac);
			return ;
		}
	}
}

void	sort_less_10_1(t_list *var, int ac)
{
	int	i;
	int	min;

	i = 0;
	while (i < var->st_a_len && var->st_a_len > 3)
	{
		min = ft_min(var->stack_a, var->st_a_len);
		if (var->stack_a[0].value == min)
			push_b(var, 1);
		else if (var->stack_a[i].value != min)
			i++;
		else if (var->stack_a[i].value == min)
		{
			ft_top_a(var, min, i, ac);
			i = 0;
		}
	}
}

void	sort_less_10_2(t_list *var, int ac)
{
	int	i;
	int	max;

	i = 0;
	if (var->st_a_len == 3)
	{
		while (!ft_is_sorted(var->stack_a, var->st_a_len))
			sort_3_a(*var);
		while (var->st_b_len)
		{
			max = ft_max(var->stack_b, var->st_b_len, &i);
			if (var->stack_b[0].value == max)
				push_a(var, ac);
			else if (var->stack_b[i].value != max)
				i++;
			else if (var->stack_b[i].value == max)
				to_top_b(var, max, i, ac);
		}
	}
}

void	sort_less_10(t_list *var, int ac)
{
	sort_less_10_1(var, ac);
	sort_less_10_2(var, ac);
}
