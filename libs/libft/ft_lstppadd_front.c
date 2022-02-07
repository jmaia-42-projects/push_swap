/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstppadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:07:45 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/01 21:20:41 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstppadd_front(t_listpp *lstpp, t_list *new)
{
	ft_lstset_next(new, lstpp->begin);
	new->next = lstpp->begin;
	lstpp->begin = new;
	if (!new->next)
		lstpp->end = lstpp->begin;
}
