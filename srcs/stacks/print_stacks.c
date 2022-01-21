/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:05:48 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/19 16:19:36 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_stacks.h"

void	print_stacks(t_stacks *stacks)
{
	ft_putstr_fd("Stack A: ", 1);
	print_stack(stacks->stack_a);
	ft_putstr_fd("\nStack B: ", 1);
	print_stack(stacks->stack_b);
	ft_putstr_fd("\n", 1);
}

void	print_stack(t_stack	*stack)
{
	t_list	*cur;

	cur = stack->lstpp->begin;
	while (cur)
	{
		ft_putnbr_fd(*(int *)cur->content, 1);
		ft_putstr_fd(" ", 1);
		cur = cur->next;
	}
}
