/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:21:32 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/29 22:02:13 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_path.h"

static t_list		*append_stacks_children(t_listpp *the_list, t_list *cur);
static t_list		*append_child_if_absent(t_listpp *the_list, t_path *cur,
						t_ops op);
static int			is_stacks_present(t_listpp *the_list, t_stacks *stacks);
static t_list	*find_better_stacks(t_list *lst, int **current_series_strengths);
t_path	*find_stacks_present(t_list *lst, t_listpp *list);
void	init_ops(t_ops ops[11]);
static int	is_better(int *strength1, int *strength2);

#include <stdio.h>

#include "get_series_strength.h"

t_path	*find_path(t_sort *sorter, t_stacks *stacks)
{
	t_path	*pathes[1000];
	t_path	*path;
	t_list	*children;
	t_list	*cur;
	t_list	*ALED;
	int		*current_series_strengths;
	int		i_path;

	path = 0;
	i_path = 0;
	cur = sorter->the_list->begin;
	current_series_strengths = get_series_strength(stacks);
	while (cur)
	{
		children = append_stacks_children(sorter->the_list, cur);
		if (children)
		{
			ALED = find_better_stacks(children, &current_series_strengths);
			if (ALED)
			{
				pathes[i_path++] = (t_path *)ALED->content;
				t_list		*new_first_elem = ft_lstnew((t_path *)ALED->content);
				t_listpp	*new_list = ft_lstppnew(new_first_elem, new_first_elem);
				cur = new_first_elem;
				if (cur->previous)
				{
					cur->previous->next = cur->next;
					cur->next = cur->previous;
				}
				cur->next = 0;
				cur->previous = 0;
				//ft_lstppclear(&sorter->the_list, &free_path_wrapper);
				sorter->the_list = new_list;
				continue;
			}
			path = find_stacks_present(children, sorter->sorted_list);
			if (path)
			{
				printf("DO SOMETHING HERE %p\n", pathes);
				return (0);
			}
		}
		cur = cur->next;
	}
	return (path);
}

static t_list	*find_better_stacks(t_list *lst, int **current_series_strength)
{
	t_list	*better_path;
	t_list	*cur;

	better_path = 0;
	cur = lst;
	while (cur)
	{
		if (is_better(get_series_strength(((t_path *)cur->content)->stacks), *current_series_strength))
		{
			*current_series_strength = get_series_strength(((t_path *)cur->content)->stacks);
			better_path = cur;
		}
		cur = cur->next;
	}
	return (better_path);
}

static int	is_better(int *strength1, int *strength2)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (strength1[i] > strength2[i])
			return (1);
		else if(strength1[i] < strength2[i])
			return (0);
		i++;
	}
	return (0);
}

t_path	*find_stacks_present(t_list *lst, t_listpp *list)
{
	t_list		*cur;
	t_stacks	*cur_stacks;

	cur = lst;
	while (cur)
	{
		cur_stacks = ((t_path *)cur->content)->stacks;
		if (ft_lstequals(cur_stacks->stack_a->lstpp->begin, list->begin))
			return ((t_path *) cur->content);
		cur = cur->next;
	}
	return (0);
}

static t_list	*append_stacks_children(t_listpp *the_list, t_list *cur)
{
	t_list	*children;
	t_list	*child;
	t_ops	ops[11];
	int		i;

	init_ops(ops);
	children = 0;
	i = 0;
	while (i < 11)
	{
		child = append_child_if_absent(the_list, (t_path *)cur->content, ops[i]);
		if (!children)
			children = child;
		i++;
	}
	return (children);
}

static t_list	*append_child_if_absent(t_listpp *the_list, t_path *p_path,
		t_ops op)
{
	t_path	*child;
	t_list	*child_lst;

	if (p_path->op && !ft_strcmp(op.op_name, get_inv_op_of(p_path->op)))
		return (0);
	child = get_path(0, p_path, op.op_name);
	child->stacks = clone_stacks(p_path->stacks);
	if (!child->stacks)
	{
		free_path(&child);
		return (0);
	}
	op.op(child->stacks);
	(void) is_stacks_present;
	if (is_stacks_present(the_list, child->stacks))
	{
		free_path(&child);
		return (0);
	}
	child_lst = ft_lstnew(child);
	ft_lstppadd_back(the_list, child_lst);
	return (child_lst);
}

static int	is_stacks_present(t_listpp *the_list, t_stacks *stacks)
{
	t_list		*cur;
	t_stacks	*cur_stacks;

	cur = the_list->begin;
	while (cur)
	{
		cur_stacks = ((t_path *) cur->content)->stacks;
		if (ft_lstequals(cur_stacks->stack_a->lstpp->begin,
				stacks->stack_a->lstpp->begin)
			&& ft_lstequals(cur_stacks->stack_b->lstpp->begin,
				stacks->stack_b->lstpp->begin))
			return (1);
		cur = cur->next;
	}
	return (0);
}
