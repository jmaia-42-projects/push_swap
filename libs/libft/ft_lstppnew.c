/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstppnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:57:41 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/19 15:58:35 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_listpp	*ft_lstppnew(t_list *begin, t_list *end)
{
	t_listpp	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (0);
	new->begin = begin;
	new->end = end;
	return (new);
}
