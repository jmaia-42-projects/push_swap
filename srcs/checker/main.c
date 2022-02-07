/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:57:13 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/07 21:22:44 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"
#include "parse_stack_a.h"
#include "print_error.h"
#include "check_sorting.h"

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	int			err;

	if (ac == 1)
		return (0);
	stacks = get_stacks(0, 0);
	if (!stacks)
	{
		print_error();
		return (1);
	}
	stacks->stack_a = parse_stack_a(ac, av);
	stacks->stack_b = get_stack();
	if (!stacks->stack_a || !stacks->stack_b)
	{
		free_stacks(stacks, 1);
		print_error();
		return (1);
	}
	err = !check_sorting(stacks);
	if (err)
		print_error();
	free_stacks(stacks, 1);
	return (0);
}
