/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstppcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:29:45 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/19 16:47:32 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_listpp	*ft_lstppcpy(t_listpp *lstpp)
{
	t_listpp	*cpy;

	cpy = malloc(sizeof(*cpy));
	if (!cpy)
		return (0);
	cpy->begin = ft_lstcpy(lstpp->begin);
	if (!cpy->begin && lstpp->begin)
	{
		free(cpy);
		return (0);
	}
	cpy->end = ft_lstlast(cpy->begin);
	return (cpy);
}
