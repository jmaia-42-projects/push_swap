/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:08:19 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/07 16:38:39 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_stack_a.h"

static int		check_args(int ac, char **av);

t_stack	*parse_stack_a(int ac, char **av)
{
	int		i;
	int		err;
	t_stack	*stack;

	err = !check_args(ac, av);
	if (err)
		return (0);
	i = ac - 1;
	stack = get_stack();
	if (!stack)
		return (0);
	while (i >= 1 && !err)
	{
		err = !push_elem(stack, ft_atoi(av[i]));
		if (err)
			ft_lstppclear(&stack->lstpp, &free);
		i--;
	}
	return (stack);
}

static int	check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		if (!ft_isint(av[i]))
			return (0);
		j = 1;
		while (j < i)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
