/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:21:32 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/28 21:24:34 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_path.h"

static t_list		*append_stacks_children(t_listpp *the_list, t_list *cur);
static t_list		*append_child_if_absent(t_listpp *the_list, t_path *cur,
						t_ops op);
static int			is_stacks_present(t_listpp *the_list, t_stacks *stacks);
void	print_path(t_path *path);

static int	get_parent_path_depth(t_path	*path)
{
	int	i;

	i = 0;
	while (path)
	{
		path = path->parent_path;
		i++;
	}
	return (i);
}


t_path	*find_path(t_sort *sorter, t_stacks *stacks)
{
	t_path	*path;
	t_list	*children;
	t_list	*cur;
	int			path_found;

	path = 0;
	path_found = 0;
	cur = sorter->the_list->begin;
	while (cur && (path_found == 0 || path_found == get_parent_path_depth((t_path *)cur->content)))
	{
		children = append_stacks_children(sorter->the_list, cur);
		if (children)
		{
			path = find_stacks_present(children, stacks);
			if (path)
				path_found = get_parent_path_depth((t_path *) cur->content);
		}
		cur = cur->next;
	}
	return (path);
}

#include <stdio.h>

t_path	*find_stacks_present(t_list *lst, t_stacks *stacks)
{
	t_list		*cur;
	t_stacks	*cur_stacks;
	t_path		*is_yes;

	cur = lst;
	is_yes = 0;
	while (cur)
	{
		cur_stacks = ((t_path *)cur->content)->stacks;
		if (ft_lstequals(cur_stacks->stack_a->lstpp->begin,
				stacks->stack_a->lstpp->begin)
			&& ft_lstequals(cur_stacks->stack_b->lstpp->begin,
				stacks->stack_b->lstpp->begin))
		{
			is_yes = (t_path *)cur->content;
			print_path((t_path *) cur->content);
			printf("----------------------\n");
		}
		cur = cur->next;
	}
	return (is_yes);
}

static t_list	*append_stacks_children(t_listpp *the_list, t_list *cur)
{
	t_list	*children;
	t_list	*child;
	t_ops	inv_ops[11];
	int		i;

	init_inv_ops(inv_ops);
	children = 0;
	i = 0;
	while (i < 11)
	{
		child = append_child_if_absent(the_list, (t_path *)cur->content,
				inv_ops[i]);
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

//	if (p_path->op && !ft_strcmp(op.op_name, get_inv_op_of(p_path->op)))
//		return (0);
	child = get_path(0, p_path, op.op_name);
	child->stacks = clone_stacks(p_path->stacks);
	if (!child->stacks)
	{
		free_path(&child);
		return (0);
	}
	(void) is_stacks_present;
	op.inv_op(child->stacks);
//	if (is_stacks_present(the_list, child->stacks))
//	{
//		free_path(&child);
//		return (0);
//	}
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
