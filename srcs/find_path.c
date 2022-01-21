/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:21:32 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/21 14:40:31 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_path.h"

static t_list	*append_stacks_children(t_listpp *the_list, t_list *cur);
static void		init_inv_ops(t_ops inv_ops[11]);
static t_list	*append_child_if_absent(t_listpp *the_list, t_path *cur,
		t_ops op);
static const char	*get_inv_op_of(const char *op);
static int	is_stacks_present(t_listpp *the_list, t_stacks *stacks);

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

static t_list *append_child_if_absent(t_listpp *the_list, t_path *p_path,
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
	op.inv_op(child->stacks);
	if (is_stacks_present(the_list, child->stacks))
	{
		free_path_but_content(child);
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
		if (ft_lstequals(cur_stacks->stack_a->lstpp->begin, stacks->stack_a->lstpp->begin) && ft_lstequals(cur_stacks->stack_b->lstpp->begin, stacks->stack_b->lstpp->begin))
			return (1);
		cur = cur->next;
	}
	return (0);
}

static const char	*get_inv_op_of(const char *op)
{
	if (!ft_strcmp(op, "sa"))
		return ("sa");
	if (!ft_strcmp(op, "sb"))
		return ("sb");
	if (!ft_strcmp(op, "ss"))
		return ("ss");
	if (!ft_strcmp(op, "pa"))
		return ("pb");
	if (!ft_strcmp(op, "pb"))
		return ("pa");
	if (!ft_strcmp(op, "ra"))
		return ("rra");
	if (!ft_strcmp(op, "rb"))
		return ("rrb");
	if (!ft_strcmp(op, "rr"))
		return ("rrr");
	if (!ft_strcmp(op, "rra"))
		return ("ra");
	if (!ft_strcmp(op, "rrb"))
		return ("rb");
	if (!ft_strcmp(op, "rrr"))
		return ("rr");
	return (0);
}

static void	init_inv_ops(t_ops inv_ops[11])
{
	inv_ops[0] = (t_ops) {.inv_op = &inv_sa, .op_name = "sa"};
	inv_ops[1] = (t_ops) {.inv_op = &inv_sb, .op_name = "sb"};
	inv_ops[2] = (t_ops) {.inv_op = &inv_ss, .op_name = "ss"};
	inv_ops[3] = (t_ops) {.inv_op = &inv_pa, .op_name = "pa"};
	inv_ops[4] = (t_ops) {.inv_op = &inv_pb, .op_name = "pb"};
	inv_ops[5] = (t_ops) {.inv_op = &inv_ra, .op_name = "ra"};
	inv_ops[6] = (t_ops) {.inv_op = &inv_rb, .op_name = "rb"};
	inv_ops[7] = (t_ops) {.inv_op = &inv_rr, .op_name = "rr"};
	inv_ops[8] = (t_ops) {.inv_op = &inv_rra, .op_name = "rra"};
	inv_ops[9] = (t_ops) {.inv_op = &inv_rrb, .op_name = "rrb"};
	inv_ops[10] = (t_ops) {.inv_op = &inv_rrr, .op_name = "rrr"};
}

void	free_path_but_content(void *param)
{
	t_path	*path;

	path = (t_path *) param;
	free_stacks(path->stacks, 0);
	free_path(&path);
}
