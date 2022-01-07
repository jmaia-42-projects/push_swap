/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:04:18 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/07 13:35:06 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

int	push_elem(t_stack *stack, int elem)
{
	t_list	*node;
	int		*elem_ptr;

	elem_ptr = malloc(sizeof(*elem_ptr));
	if (!elem_ptr)
		return (0);
	*elem_ptr = elem;
	node = ft_lstnew(elem_ptr);
	if (!node)
	{
		free(elem_ptr);
		return (0);
	}
	ft_lstadd_front(&stack->list, node);
	return (1);
}
