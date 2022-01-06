/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:04:18 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/06 18:39:06 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

int		push_elem(t_list **stack, int elem)
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
	ft_lstadd_front(stack, node);
	return (1);
}
