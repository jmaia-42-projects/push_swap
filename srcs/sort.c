/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:13:21 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/12 18:26:26 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static t_sort	*init_sorter(t_stacks *stacks);
static t_list	*basic_sort(t_list *list);

void	print_sort(t_stacks *stacks)
{
	t_sort	*sorter;
	t_list	*path;

	sorter = init_sorter(stacks);
	if (!sorter)
		return ;
	path = find_path(sorter, stacks);
	if (path)
		print_path(path);
	ft_lstclear(&path, &free);
	free_sorter(&sorter);
}

static t_sort	*init_sorter(t_stacks *stacks)
{
	t_sort	*sorter;

	sorter = malloc(sizeof(*sorter));
	if (!sorter)
		return (0);
	sorter->sorted_list = ft_lstsort(stacks->stack_a->list);
	sorter->the_list = ft_lstnew(sorted_list);
	sorter->paths = 0;
	if (!sorter->sorted_list || !sorter->the_list)
	{
		free_sorter(&sorter);
		return (0);
	}
	return (sorter);
}

void	free_sorter(t_sort **sorter)
{
	ft_lstclear(&(*sorter)->sorted_list);
	ft_lstclear(&(*sorter)->the_list);
	ft_lstclear(&(*sorter)->paths);
	free(*sorter);
	*sorter = 0;
}
