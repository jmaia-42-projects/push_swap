/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inv_op_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:35:12 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/30 15:35:35 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inv_op_utils.h"

static void	shuffle(t_ops inv_ops[11]);

const char	*get_inv_op_of(const char *op)
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

void	init_inv_ops(t_ops inv_ops[11])
{
	inv_ops[0] = (t_ops){.inv_op = &inv_sa, .op_name = "sa"};
	inv_ops[1] = (t_ops){.inv_op = &inv_sb, .op_name = "sb"};
	inv_ops[2] = (t_ops){.inv_op = &inv_ss, .op_name = "ss"};
	inv_ops[3] = (t_ops){.inv_op = &inv_ra, .op_name = "ra"};
	inv_ops[4] = (t_ops){.inv_op = &inv_rb, .op_name = "rb"};
	inv_ops[5] = (t_ops){.inv_op = &inv_rr, .op_name = "rr"};
	inv_ops[6] = (t_ops){.inv_op = &inv_rra, .op_name = "rra"};
	inv_ops[7] = (t_ops){.inv_op = &inv_rrb, .op_name = "rrb"};
	inv_ops[8] = (t_ops){.inv_op = &inv_rrr, .op_name = "rrr"};
	inv_ops[9] = (t_ops){.inv_op = &inv_pa, .op_name = "pa"};
	inv_ops[10] = (t_ops){.inv_op = &inv_pb, .op_name = "pb"};
	shuffle(inv_ops);
}

#include <time.h>
#include <limits.h>

static void	shuffle(t_ops inv_ops[11])
{
	int		i;
	int		j;
	t_ops	tmp;

	srand(time(0));
	i = 0;
	while (i < 11)
	{
		j = i + rand() / (INT_MAX / (11 - i));
		if (j != 11)
		{
			tmp = inv_ops[i];
			inv_ops[i] = inv_ops[j];
			inv_ops[j] = tmp;
		}
		i++;
	}
}
