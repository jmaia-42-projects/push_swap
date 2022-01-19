/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstbreaklink.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:37:28 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/19 14:40:01 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstbreaklink(t_list *lst1, t_list *lst2)
{
	if (!lst1 || !lst2)
		return ;
	if (lst1->next == lst2)
		lst1->next = 0;
	if (lst1->previous == lst2)
		lst1->previous = 0;
	if (lst2->next == lst1)
		lst2->next = 0;
	if (lst2->previous == lst1)
		lst2->previous = 0;
}
