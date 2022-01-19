/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:28:04 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/19 22:49:11 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	(void) lst;
	(void) del;
//	t_list	*cur;
//
//	if (lst == 0 || *lst == 0)
//		return ;
//	cur = *lst;
//	while (cur)
//	{
//		if (del)
//			del(cur->content);
//		free(cur);
//		cur = cur->next;
//	}
//	*lst = 0;
}
