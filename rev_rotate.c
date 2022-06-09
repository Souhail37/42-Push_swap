/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:34:24 by sismaili          #+#    #+#             */
/*   Updated: 2022/04/26 02:44:32 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rev_rot_a(t_list var)
{
	ft_revrot(var.stack_a, var.st_a_len);
	ft_printf("rra\n");
}

void	rev_rot_b(t_list var)
{
	ft_revrot(var.stack_b, var.st_b_len);
	ft_printf("rrb\n");
}

void	ft_rrr(t_list var)
{
	ft_revrot(var.stack_a, var.st_a_len);
	ft_revrot(var.stack_b, var.st_b_len);
	ft_printf("rrr\n");
}
