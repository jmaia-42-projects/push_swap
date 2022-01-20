/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:28:04 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/20 17:55:48 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

//REMOVE
#include <stdio.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*next;

	if (lst == 0 || *lst == 0)
		return ;
	cur = *lst;
	while (cur)
	{
		if (del)
			del(cur->content);
		printf("%p\n", cur);
		next = cur->next;
		free(cur);
		cur = next;
	}
	*lst = 0;
}
