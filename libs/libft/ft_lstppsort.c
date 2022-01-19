/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstppsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:50:53 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/19 15:53:05 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_listpp	*ft_lstppsort(t_list *lst, int (*cmp)(void *, void *))
{
	t_listpp	*sorted_list;

	sorted_list = malloc(sizeof(*sorted_list));
	if (!sorted_list)
		return (0);
	sorted_list->begin = ft_lstsort(lst, cmp);
	if (!sorted_list->begin)
	{
		free(sorted_list);
		return (0);
	}
	sorted_list->end = ft_lstlast(sorted_list->begin);
	return (sorted_list);
}
