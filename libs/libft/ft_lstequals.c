/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstequals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:39:10 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/17 16:41:46 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstequals(t_list *lst1, t_list *lst2)
{
	t_list	*cur1;
	t_list	*cur2;

	cur1 = lst1;
	cur2 = lst2;
	while (cur1 && cur2)
	{
		if (cur1->content != cur2->content)
			return (0);
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return (!cur1 && !cur2);
}
