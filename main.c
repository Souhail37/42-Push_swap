/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:07:52 by sismaili          #+#    #+#             */
/*   Updated: 2022/09/03 15:46:15 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_list *var)
{
	int	i;

	i = 0;
	while (var->spl[i])
		free(var->spl[i++]);
	free(var->spl);
	free(var->str);
	if (var->stack_a)
		free(var->stack_a);
	if (var->stack_b)
		free(var->stack_b);
}

int	main(int ac, char **av)
{
	t_list	var;

	if (ac > 1)
	{
		var.i = 0;
		var.j = 0;
		if (validarg(av + 1))
			return (1);
		ft_joinargs(&var.str, av);
		var.spl = ft_split(var.str, ' ');
		while (var.spl[var.j])
			var.j++;
		if (!check_number(var.spl, var.i) || !check_double(var.spl, var.i)
			|| !check_int(var.j, var.spl))
			return (ft_free(&var), 1);
		var.stack_a = malloc(sizeof(t_stack) * var.j);
		var.stack_b = malloc(sizeof(t_stack) * var.j);
		if (!var.stack_a || !var.stack_b)
			return (0);
		var.st_a_len = var.j;
		var.st_b_len = 0;
		ft_done(var, var.spl, var.j);
		ft_free(&var);
	}
	return (0);
}
