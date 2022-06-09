/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 02:52:27 by sismaili          #+#    #+#             */
/*   Updated: 2022/04/26 02:54:12 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate(t_stack *var, int size)
{
	int		i;
	t_stack	temp;

	i = 1;
	while (i < size)
	{
		temp = var[i];
		var[i] = var[i - 1];
		var[i - 1] = temp;
		i++;
	}
}

void	rot1_a(t_list var)
{
	ft_rotate(var.stack_a, var.st_a_len);
}

void	rot1_b(t_list var)
{
	ft_rotate(var.stack_b, var.st_b_len);
}

void	ft_rr1(t_list var)
{
	ft_rotate(var.stack_a, var.st_a_len);
	ft_rotate(var.stack_b, var.st_b_len);
}
