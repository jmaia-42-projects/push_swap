/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstppclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:10:54 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/19 16:29:05 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstppclear(t_listpp **lstpp, void (*del)(void *))
{
	if (!lstpp)
		return ;
	ft_lstclear(&(*lstpp)->begin, del);
	free(*lstpp);
	*lstpp = 0;
}
