/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double_distance_of.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:08:06 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/07 14:08:13 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_double_distance_of.h"

void	get_double_distance_of(t_stack *stack, int elem, int distances[2])
{
	t_list	*cur;
	int		i;

	i = 0;
	cur = stack->lstpp->begin;
	while (cur && *(int *)cur->content != elem)
	{
		i++;
		cur = cur->next;
	}
	distances[1] = i;
	distances[0] = -(ft_lstsize(stack->lstpp->begin) - i);
}
