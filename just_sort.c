/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 02:34:49 by sismaili          #+#    #+#             */
/*   Updated: 2022/04/26 18:00:00 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_step(t_list *var, int number, int ac)
{
	int		size;
	int		save;

	size = var->st_a_len;
	size /= number;
	save = size;
	while (var->st_a_len)
	{
		to_top_a(var, size, save, ac);
		size += save;
	}
}

void	second_step(t_list *var, int ac)
{
	int	i;
	int	max;

	while (var->st_b_len)
	{
		max = ft_max(var->stack_b, var->st_b_len, &i);
		to_top_b(var, max, i, ac);
	}
}

void	just_sort(t_list *var, int number, int ac)
{
	t_stack	*temp;

	temp = malloc(sizeof(t_stack) * ac);
	copy_element(temp, var->stack_a, ac);
	simple_sort(temp, var->st_a_len);
	take_index(temp, var->stack_a, var->st_a_len);
	first_step(var, number, ac);
	second_step(var, ac);
	free (temp);
}
