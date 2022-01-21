/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:13:07 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/21 15:44:17 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

# include "stacks.h"

typedef struct s_path
{
	t_stacks		*stacks;
	struct s_path	*parent_path;
	const char		*op;
}	t_path;

t_path	*get_path(t_stacks *stacks, t_path *parent_path, const char *op);
t_path	*clone_path(t_path *path);
void	free_path(t_path **path);
void	free_path_wrapper(void *param);

#endif
