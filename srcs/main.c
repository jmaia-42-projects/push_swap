/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:18:13 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/06 18:37:05 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stacks.h"
#include "libft.h"
#include "sort.h"

static t_list	*parse_stack_a(int ac, char **av);
static void	check_args(int ac, char **av);

int main(int ac, char **av)
{
	t_list		*stack_a;
	t_stacks	*stacks;

	if (ac == 1)
		return (0);
	stack_a = parse_stack_a(ac, av);
	stacks = get_stacks(stack_a, 0);
	print_sort(stacks);
	return (0);
}

static t_list	*parse_stack_a(int ac, char **av)
{
	int		i;
	t_list	*stack;

	check_args(ac, av);
	i = 1;
	while (i < ac)
	{
		push_elem(&stack, atoi(av[i]));
		i++;
	}
	return (stack);
}

static void	check_args(int ac, char **av)
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
