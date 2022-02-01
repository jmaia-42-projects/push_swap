/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:50:46 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/01 16:17:55 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

static t_op	how_do_i_rule_these_stacks(t_stacks *stacks);

t_rule	get_rule_bubble_move(void)
{
	return (&how_do_i_rule_these_stacks);
}

static t_op	how_do_i_rule_these_stacks(t_stacks *stacks)
{
	t_op	op;
	int		who_moves;
	int		direction;

	who_moves = get_best_movable(stacks->stack_a);
	op.op = 0;
	if ((who_moves == 0 && direction == -1) || (who_moves == 1 && direction == 1))
	{
		op.op = &sa;
		op.op_name = "sa\n"
	}
	else if (who_moves == 0 && direction == 1)
	{
		op.op = &rra;
		op.op_name = "rra\n";
	}
	else if (who_moves == 1 && direction == -1)
	{
		op.op = &ra;
		op.op_name = "ra\n";
	}
	return (op);
}

static int	get_best_movable(t_stack *stack)
{
	int	elem1;
	int	elem2;
	int	dist1;
	int	dist2;
	int	end_pos1;
	int	end_pos2;

	elem1 = *(int *)stack->lstpp->begin->content;
	elem2 = *(int *)stack->lstpp->begin->next->content;
	end_pos1 = where_do_i_want_to_go(stack, elem1);
	end_pos2 = where_do_i_want_to_go(stack, elem2);
	dist1 = get_relative_distance(0, end_pos1);
	dist2 = get_relative_distance(1, end_pos2);
	if (abs(dist1) < abs(dist2))
		return (0);
	else
		return (1);
}

static int	get_relative_distance(int start, int end)
{
	
}

static int	abs(int n)
{
	return ((n > 0) * n + !(n > 0) * -n);
}

static int	where_do_i_want_to_go(t_stack *stack, int elem)
{
	t_list	*cur;
	int		cur_content;
	int		i;
	int		found;

	cur = stacks->lstpp->begin;
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
