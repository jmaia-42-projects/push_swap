/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:22:54 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/17 16:13:27 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"
#include <stdlib.h>

void	free_stacks(t_stacks *stacks, int do_free_content)
{
	free_stack(stacks->stack_a, do_free_content);
	free_stack(stacks->stack_b, do_free_content);
	free(stacks);
}

void	free_stack(t_stack *stack, int do_free_content)
{
	if (do_free_content)
		ft_lstclear(&stack->list, &free);
	else
		ft_lstclear(&stack->list, 0);
	free(stack);
}
