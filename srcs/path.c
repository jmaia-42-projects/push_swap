/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:17:28 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/18 15:15:16 by jmaia            ###   ########.fr       */
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

void	free_path(t_path **path)
{
	free(*path);
	*path = 0;
}
