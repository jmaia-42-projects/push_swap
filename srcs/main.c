/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:18:13 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/05 18:21:11 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static t_stack	*parse_stack_a(int ac, char **av);

int main(int ac, char **av)
{
	t_stack	*stack_a;

	if (ac == 1)
		return (0);
	stack_a = parse_stack_a(ac, av);
//	print_sort(stack_a);
	return (0);
}

static t_stack	*parse_stack_a(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		if (!ft_isint(av[i]))
			exit(1);
		j = 1;
		while (j < i)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				exit(2);
			j++;
		}
	}
}
