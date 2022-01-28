/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:04:18 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/28 19:02:37 by jmaia            ###   ########.fr       */
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
	if (stack->lstpp->begin && stack->lstpp->begin->next)
		stack->checksum -= checksum(*(int *)stack->lstpp->end->content, *(int *) stack->lstpp->begin->content);
	ft_lstppadd_front(stack->lstpp, node);
	if (stack->lstpp->begin->next)
	{
		stack->checksum += checksum(*(int *)stack->lstpp->end->content, elem);
		stack->checksum += checksum(elem, *(int *)stack->lstpp->begin->next->content);
	}
	return (1);
}
