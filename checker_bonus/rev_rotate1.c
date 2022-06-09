/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 02:51:40 by sismaili          #+#    #+#             */
/*   Updated: 2022/04/26 02:54:10 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_revrot(t_stack *var, int size)
{
	int		i;
	t_stack	temp;

	i = size - 1;
	while (i > 0)
	{
		temp = var[i];
		var[i] = var[i - 1];
		var[i - 1] = temp;
		i--;
	}
}

void	rev_rot1_a(t_list var)
{
	ft_revrot(var.stack_a, var.st_a_len);
}

void	rev_rot1_b(t_list var)
{
	ft_revrot(var.stack_b, var.st_b_len);
}

void	ft_rrr1(t_list var)
{
	ft_revrot(var.stack_a, var.st_a_len);
	ft_revrot(var.stack_b, var.st_b_len);
}
