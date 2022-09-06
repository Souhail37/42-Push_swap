/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:38:39 by sismaili          #+#    #+#             */
/*   Updated: 2022/09/06 13:05:17 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_element(t_stack *temp, t_stack *stack, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		temp[i].value = stack[i].value;
		i++;
	}
}

void	simple_sort(t_stack *array, int size)
{
	int	step;
	int	i;
	int	temp;

	step = 0;
	while (step < size - 1)
	{
		i = 0;
		while (i < size - step - 1)
		{
			if (array[i].value > array[i + 1].value)
			{
				temp = array[i].value;
				array[i].value = array[i + 1].value;
				array[i + 1].value = temp;
			}
			i++;
		}
		step++;
	}
}

void	take_index(t_stack *temp, t_stack *stack, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (temp[i].value == stack[j].value)
		{
			stack[j].pos = i;
			j = 0;
			i++;
		}
		else
			j++;
	}
}

void	to_top_a(t_list *var, int size, int save, int ac)
{
	int	i;

	i = 0;
	while (ft_isthere(var, size))
	{
		if (var->stack_a[0].pos < size)
		{
			push_b(var, ac);
			if (var->stack_b[0].pos < size - (save / 2))
			{
				if (var->stack_a[0].pos > size)
					ft_rr(*var);
				else
					rot_b(*var);
			}
		}
		else
			rot_a(*var);
		i++;
	}
}

void	to_top_b(t_list *var, int max, int i, int ac)
{
	if (var->stack_b[0].value == max)
	{
		push_a(var, ac);
		return ;
	}
	if (var->stack_b[1].value == max)
	{
		swap_b(*var);
		push_a(var, ac);
		return ;
	}
	while (var->stack_b[0].value != max)
	{
		if (i >= var->st_b_len / 2)
			rev_rot_b(*var);
		else
			rot_b(*var);
		if (var->stack_b[0].value == max)
		{
			push_a(var, ac);
			return ;
		}
	}
}
