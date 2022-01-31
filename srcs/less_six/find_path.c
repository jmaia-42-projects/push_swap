/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:21:32 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/31 22:20:24 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_path.h"

static t_list		*append_stacks_children(t_listpp *the_list, t_list *cur);
static t_list		*append_child_if_absent(t_listpp *the_list, t_path *cur,
						t_op op);
static int			is_stacks_present(t_listpp *the_list, t_stacks *stacks);

t_path	*find_path(t_sort *sorter, t_stacks *stacks)
{
	t_path	*path;
	t_list	*children;
	t_list	*cur;

	path = 0;
	cur = sorter->the_list->begin;
	while (cur)
	{
		children = append_stacks_children(sorter->the_list, cur);
		if (children)
		{
			path = find_stacks_present(children, stacks);
			if (path)
				return (path);
		}
		cur = cur->next;
	}
	return (path);
}

t_path	*find_stacks_present(t_list *lst, t_stacks *stacks)
{
	t_list		*cur;
	t_stacks	*cur_stacks;

	cur = lst;
	while (cur)
	{
		cur_stacks = ((t_path *)cur->content)->stacks;
		if (ft_lstequals(cur_stacks->stack_a->lstpp->begin,
				stacks->stack_a->lstpp->begin)
			&& ft_lstequals(cur_stacks->stack_b->lstpp->begin,
				stacks->stack_b->lstpp->begin))
			return ((t_path *) cur->content);
		cur = cur->next;
	}
	return (0);
}

static t_list	*append_stacks_children(t_listpp *the_list, t_list *cur)
{
	t_list	*children;
	t_list	*child;
	t_op	inv_ops[11];
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
		t_op op)
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
