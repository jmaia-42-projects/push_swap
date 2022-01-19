/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:18:13 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/19 15:09:51 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "stacks.h"
#include "libft.h"
#include "sort.h"

static t_stack	*parse_stack_a(int ac, char **av);
static int		check_args(int ac, char **av);
static int		print_error(void);

int	main(int ac, char **av)
{
	t_stacks	*stacks;

	if (ac == 1)
		return (0);
	stacks = get_stacks(0, 0);
	if (!stacks)
		return (print_error());
	stacks->stack_a = parse_stack_a(ac, av);
	stacks->stack_b = get_stack();
	if (!stacks->stack_a || !stacks->stack_b)
	{
		free_stacks(stacks, 1);
		return (print_error());
	}
	print_sort(stacks);
	free_stacks(stacks, 1);
	return (0);
}

static t_stack	*parse_stack_a(int ac, char **av)
{
	int		i;
	int		err;
	t_stack	*stack;

	err = !check_args(ac, av);
	if (err)
		exit(print_error());
	i = ac - 1;
	stack = get_stack();
	if (!stack)
		return (0);
	while (i >= 1 && !err)
	{
		err = !push_elem(stack, atoi(av[i]));
		if (err)
			ft_lstppclear(&stack->lstpp, &free);
		i--;
	}
	if (err)
		print_error();
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

static int	print_error(void)
{
	ssize_t	pouet;
	
	pouet = write(2, "Error\n", 6);
	(void) pouet;
	return (1);
}
