/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:57:13 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/07 16:03:39 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char **av)
{
	t_stacks	*stacks;

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
	if (ft_lstsize(stacks->stack_a->lstpp->begin) <= 1)
		print_sort_less_six(stacks);
	else
		print_sort_general(stacks);
	free_stacks(stacks, 1);
	return (0);
}
