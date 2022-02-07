/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_to_the_top.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:17:42 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/07 15:30:36 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bring_to_the_top.h"

static void	apply_rotates(t_stacks *stacks, int rotates[3]);
static void	init_actions(t_ops ops[6]);
static void	find_best_rotates(int costs[4], int rotates[3], int dist0[2],
				int dist1[2]);
static void	find_best_rotates_2_tmtc(int best_i, int rotates[3], int dist0[2],
				int dist1[2]);

void	bring_to_the_top(t_stacks *stacks, int elems[2])
{
	int	rotates[3];
	int	dist0[2];
	int	dist1[2];
	int	costs[4];

	get_double_distance_of(stacks->stack_a, elems[0], dist0);
	get_double_distance_of(stacks->stack_b, elems[1], dist1);
	costs[0] = ft_max(-dist0[0], -dist1[0]);
	costs[1] = -dist0[0] + dist1[1];
	costs[2] = dist0[1] - dist1[0];
	costs[3] = ft_max(dist0[1], dist1[1]);
	find_best_rotates(costs, rotates, dist0, dist1);
	apply_rotates(stacks, rotates);
}

static void	find_best_rotates(int costs[4], int rotates[3], int dist0[2],
				int dist1[2])
{
	int	i;
	int	cost;
	int	best_i;

	cost = -1;
	i = 0;
	while (i < 4)
	{
		if (costs[i] < cost || cost == -1)
		{
			cost = costs[i];
			best_i = i;
		}
		i++;
	}
	find_best_rotates_2_tmtc(best_i, rotates, dist0, dist1);
	if (best_i == 3)
	{
		rotates[0] = ft_min(dist0[1], dist1[1]);
		if (dist0[1] > dist1[1])
			rotates[1] = dist0[1] - dist1[1];
		else
			rotates[2] = dist1[1] - dist0[1];
	}
}

static void	find_best_rotates_2_tmtc(int best_i, int rotates[3], int dist0[2],
				int dist1[2])
{
	rotates[0] = 0;
	rotates[1] = 0;
	rotates[2] = 0;
	if (best_i == 0)
	{
		rotates[0] = ft_max(dist0[0], dist1[0]);
		if (dist0[0] < dist1[0])
			rotates[1] = dist0[0] - dist1[0];
		else
			rotates[2] = dist1[0] - dist0[0];
	}
	if (best_i == 1)
	{
		rotates[1] = dist0[0];
		rotates[2] = dist1[1];
	}
	if (best_i == 2)
	{
		rotates[1] = dist0[1];
		rotates[2] = dist1[0];
	}
}

static void	apply_rotates(t_stacks *stacks, int rotates[3])
{
	int		i;
	int		j;
	t_ops	actions[6];

	init_actions(actions);
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < ft_abs(rotates[i]))
		{
			if (rotates[i] > 0)
			{
				actions[i * 2].op(stacks);
				write(1, actions[i * 2].op_name, 3);
			}
			else
			{
				actions[i * 2 + 1].op(stacks);
				write(1, actions[i * 2 + 1].op_name, 4);
			}
			j++;
		}
		i++;
	}
}

static void	init_actions(t_ops ops[6])
{
	ops[0].op_name = "rr\n";
	ops[0].op = &rr;
	ops[1].op_name = "rrr\n";
	ops[1].op = &rrr;
	ops[2].op_name = "ra\n";
	ops[2].op = &ra;
	ops[3].op_name = "rra\n";
	ops[3].op = &rra;
	ops[4].op_name = "rb\n";
	ops[4].op = &rb;
	ops[5].op_name = "rrb\n";
	ops[5].op = &rrb;
}
