/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstppadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:09:23 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/01 21:20:03 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstppadd_back(t_listpp *lstpp, t_list *new)
{
	ft_lstset_next(lstpp->end, new);
	lstpp->end = new;
	if (!new->previous)
		lstpp->begin = lstpp->end;
}
