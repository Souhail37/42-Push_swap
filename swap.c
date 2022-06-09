/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:03:24 by sismaili          #+#    #+#             */
/*   Updated: 2022/04/26 02:44:48 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *temp1, t_stack *temp2)
{
	t_stack	temp;

	temp = *temp1;
	*temp1 = *temp2;
	*temp2 = temp;
}

void	swap_a(t_list var)
{
	ft_swap(&var.stack_a[0], &var.stack_a[1]);
	ft_printf("sa\n");
}

void	swap_b(t_list var)
{
	ft_swap(&var.stack_b[0], &var.stack_b[1]);
	ft_printf("sb\n");
}

void	ft_ss(t_list var)
{
	ft_swap(&var.stack_a[0], &var.stack_a[1]);
	ft_swap(&var.stack_b[0], &var.stack_b[1]);
	ft_printf("ss\n");
}
