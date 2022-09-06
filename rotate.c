/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:18:59 by sismaili          #+#    #+#             */
/*   Updated: 2022/09/06 13:06:16 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rot_a(t_list var)
{
	ft_rotate(var.stack_a, var.st_a_len);
	ft_printf("ra\n");
}

void	rot_b(t_list var)
{
	ft_rotate(var.stack_b, var.st_b_len);
	ft_printf("rb\n");
}

void	ft_rr(t_list var)
{
	ft_rotate(var.stack_a, var.st_a_len);
	ft_rotate(var.stack_b, var.st_b_len);
	ft_printf("rr\n");
}
