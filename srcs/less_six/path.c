/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:17:28 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/21 15:45:26 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

t_path	*get_path(t_stacks *stacks, t_path *parent_path, const char *op)
{
	t_path	*path;

	path = malloc(sizeof(*path));
	if (!path)
		return (0);
	path->stacks = stacks;
	path->parent_path = parent_path;
	path->op = op;
	return (path);
}

void	free_path_wrapper(void *param)
{
	t_path	*path;

	path = (t_path *)param;
	free_path(&path);
}

void	free_path(t_path **path)
{
	if ((*path)->stacks)
		free_stacks((*path)->stacks, 0);
	free(*path);
	*path = 0;
}
