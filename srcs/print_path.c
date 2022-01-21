/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:24:43 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/18 15:47:58 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_path.h"

void	print_path(t_path *path)
{
	t_path	*cur;

	cur = path;
	while (cur->parent_path)
	{
		ft_putendl_fd((char *) cur->op, 1);
		cur = cur->parent_path;
	}
}
