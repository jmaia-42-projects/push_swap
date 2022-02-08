/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstis_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:59:59 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/08 11:02:33 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstis_sorted(t_list *lst)
{
	t_list	*sorted_list;
	int		is_sorted;

	sorted_list = ft_lstsort(lst, &intcmp);
	is_sorted = ft_lstequals(lst, sorted_list);
	ft_lstclear(&sorted_list, 0);
	return (is_sorted);
}
