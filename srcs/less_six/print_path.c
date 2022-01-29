/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:24:43 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/22 16:47:01 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_path.h"

static void	show_algo(t_path *path);
void	print_stacks(t_stacks *stacks);

void	print_path(t_path *path)
{
	t_path	*cur;

	cur = path;
	while (cur->parent_path)
	{
		ft_putendl_fd((char *) cur->op, 1);
		cur = cur->parent_path;
	}
	show_algo(path);
}

static void	show_algo(t_path *path)
{
	while (path)
	{
		print_stacks(path->stacks);
		path = path->parent_path;
	}
}
