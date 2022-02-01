/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:50:46 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/01 17:54:27 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

static t_op		how_do_i_rule_these_stacks(t_stacks *stacks);
static int		get_relative_distance_to_right_place(t_stack *stack, int elem);
static int		get_relative_distance(t_stack *stack, int elem_start, int elem_end);
static t_list	*node_search(t_list *lst, int content);
static int		where_do_i_want_to_go(t_stack *stack, int elem);
static int		ft_abs(int n);

t_rule	get_rule_bubble_move(void)
{
	return (&how_do_i_rule_these_stacks);
}

#include <stdio.h>

static t_op	how_do_i_rule_these_stacks(t_stacks *stacks)
{
	t_op	op;
	int		who_moves;
	int		dist0;
	int		dist1;

	(void) node_search;
	(void) where_do_i_want_to_go;
	dist0 = get_relative_distance_to_right_place(stacks->stack_a, 0);
	dist1 = get_relative_distance_to_right_place(stacks->stack_a, 1);
	who_moves = ft_abs(dist0) > ft_abs(dist1);
	op.op = 0;
	if ((who_moves == 0 && dist0 > 0) || (who_moves == 1 && dist1 < 0))
	{
		op.op = &sa;
		op.op_name = "sa\n";
	}
	else if (who_moves == 0 && dist0 < 0)
	{
		op.op = &rra;
		op.op_name = "rra\n";
	}
	else if (who_moves == 1 && dist1 > 0)
	{
		op.op = &ra;
		op.op_name = "ra\n";
	}
	return (op);
}

static int	get_relative_distance_to_right_place(t_stack *stack, int elem)
{
	int		i_start;
	int		i_end;
	int		i;
	int		cur_elem;
	int		stack_size;
	t_list	*cur;

	i_start = 0;
	i = 0;
	stack_size = ft_lstsize(stack->lstpp->begin);
	cur = stack->lstpp->begin;
	while (cur)
	{
		cur_elem = *(int *)cur->content;
		if (cur_elem == elem)
			i_start = i;
		else if (cur_elem == elem + 1 || (elem == stack_size && cur_elem == 1))
			i_end = i;
		i++;
		cur = cur->next;
	}
	return (get_relative_distance(stack, i_start, i_end));
}

static int	get_relative_distance(t_stack *stack, int i_start, int i_end)
{
	int	dist_forward;
	int	dist_backward;
	int	stack_size;

	stack_size = ft_lstsize(stack->lstpp->begin);
	if (i_end >= i_start)
		dist_forward = i_end - i_start;
	else
		dist_forward = stack_size - i_start + i_end;
	dist_backward = -stack_size + dist_forward;
	if (ft_abs(dist_forward) < ft_abs(dist_backward))
		return (dist_forward);
	else
		return (dist_backward);
}

static t_list	*node_search(t_list *lst, int content)
{
	t_list	*cur;

	cur = lst;
	while (cur)
	{
		if (*(int *)cur->content == content)
			return (cur);
		cur = cur->next;
	}
	return (0);
}

static int	ft_abs(int n)
{
	return ((n > 0) * n + !(n > 0) * -n);
}

static int	where_do_i_want_to_go(t_stack *stack, int elem)
{
	t_list	*cur;
	int		cur_content;
	int		i;
	int		found;

	cur = stack->lstpp->begin;
	found = 0;
	i = 0;
	while (cur && !found)
	{
		cur_content = *(int *) cur->content;
		if (elem == cur_content + 1)
			found = i;
		cur = cur->next;
		i++;
	}
	// Faudra rajouter le fait d'aller dans l'autre sens aussi
	if (!found)
		return (0);
	return (found);
}
