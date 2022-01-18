/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:13:21 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/18 16:23:21 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static t_sort	*init_sorter(t_stacks *stacks);
static int		intcmp(void *v1, void *v2);

void	print_sort(t_stacks *stacks)
{
	t_sort	*sorter;
	t_path	*path;

	sorter = init_sorter(stacks);
	if (!sorter)
		return ;
	path = find_stacks_present(sorter->the_list, stacks);
	if (!path)
		path = find_path(sorter, stacks);
	if (path)
		print_path(path);
	free_sorter(&sorter);
}

static t_sort	*init_sorter(t_stacks *stacks)
{
	t_sort		*sorter;
	t_stack		*stack_a_the_list;
	t_stacks	*stacks_the_list;
	t_path		*path_the_list;

	sorter = malloc(sizeof(*sorter));
	if (!sorter)
		return (0);
	sorter->sorted_list = ft_lstsort(stacks->stack_a->list, &intcmp);
	stack_a_the_list = get_stack();
	if (stack_a_the_list)
	{
		stack_a_the_list->list = ft_lstcpy(sorter->sorted_list);
		stacks_the_list = get_stacks(stack_a_the_list, get_stack());
		path_the_list = get_path(stacks_the_list, 0, 0);
		sorter->the_list = ft_lstnew(path_the_list);
	}
	sorter->paths = 0;
	if (!sorter->sorted_list || !sorter->the_list)
	{
		free_sorter(&sorter);
		return (0);
	}
	return (sorter);
}

static int	intcmp(void *v1, void *v2)
{
	int	*i1;
	int	*i2;

	i1 = v1;
	i2 = v2;
	return (*i1 - *i2);
}

void	free_sorter(t_sort **sorter)
{
	ft_lstclear(&(*sorter)->sorted_list, 0);
	ft_lstclear(&(*sorter)->the_list, &free_path_but_content);
	ft_lstclear(&(*sorter)->paths, &free);
	free(*sorter);
	*sorter = 0;
}
