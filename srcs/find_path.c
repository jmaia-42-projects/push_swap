/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:21:32 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/18 17:14:12 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_path.h"

static t_list	*get_stacks_children(t_path *parent_path);
static void		init_inv_ops(t_ops inv_ops[11]);

t_path	*find_path(t_sort *sorter, t_stacks *stacks)
{
	t_path	*path;
	t_list	*children;
	t_list	*next_node;

	path = 0;
	while (sorter->the_list)
	{
		children = get_stacks_children((t_path *) sorter->the_list->content);
		if (!children)
			return (0);
		path = find_stacks_present(children, stacks);
		if (path)
		{
			return (path);
		}
		ft_lstadd_back(&sorter->the_list, children);
		next_node = sorter->the_list->next;
		free(sorter->the_list);
		sorter->the_list = next_node;
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
		if (ft_lstequals(cur_stacks->stack_a->list, stacks->stack_a->list)
			&& ft_lstequals(cur_stacks->stack_b->list, stacks->stack_b->list))
			return ((t_path *) cur->content);
		cur = cur->next;
	}
	return (0);
}

static t_list	*get_stacks_children(t_path *parent_path)
{
	t_list		*children;
	t_list		*child_lst;
	t_path		*child;
	t_ops		inv_ops[11];
	int			i;

	init_inv_ops(inv_ops);
	children = 0;
	i = 0;
	while (i < 11)
	{
		child = get_path(0, parent_path, inv_ops[i].op_name);
		child->stacks = clone_stacks(parent_path->stacks);
		if (!child->stacks)
		{
			free_path(&child);
			return (0);
		}
		inv_ops[i].inv_op(child->stacks);
		child_lst = ft_lstnew(child);
		ft_lstadd_front(&children, child_lst);
		i++;
	}
	return (children);
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
