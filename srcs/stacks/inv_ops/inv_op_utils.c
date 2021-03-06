/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inv_op_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:35:12 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/07 21:39:57 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inv_op_utils.h"

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
	inv_ops[0] = (t_ops){.op = &inv_sa, .op_name = "sa"};
	inv_ops[1] = (t_ops){.op = &inv_sb, .op_name = "sb"};
	inv_ops[2] = (t_ops){.op = &inv_ss, .op_name = "ss"};
	inv_ops[3] = (t_ops){.op = &inv_pa, .op_name = "pa"};
	inv_ops[4] = (t_ops){.op = &inv_pb, .op_name = "pb"};
	inv_ops[5] = (t_ops){.op = &inv_ra, .op_name = "ra"};
	inv_ops[6] = (t_ops){.op = &inv_rb, .op_name = "rb"};
	inv_ops[7] = (t_ops){.op = &inv_rr, .op_name = "rr"};
	inv_ops[8] = (t_ops){.op = &inv_rra, .op_name = "rra"};
	inv_ops[9] = (t_ops){.op = &inv_rrb, .op_name = "rrb"};
	inv_ops[10] = (t_ops){.op = &inv_rrr, .op_name = "rrr"};
}

t_ops	get_op(const char *raw_op)
{
	t_ops	op;
	t_ops	ops[11];
	int		i;

	get_ops(ops);
	i = 0;
	op.op = 0;
	op.op_name = 0;
	while (i < 11)
	{
		if (!ft_strcmp(raw_op, ops[i].op_name))
			return (ops[i]);
		i++;
	}
	return (op);
}

void	get_ops(t_ops ops[11])
{
	ops[0] = (t_ops){.op = &sa, .op_name = "sa"};
	ops[1] = (t_ops){.op = &sb, .op_name = "sb"};
	ops[2] = (t_ops){.op = &ss, .op_name = "ss"};
	ops[3] = (t_ops){.op = &pa, .op_name = "pa"};
	ops[4] = (t_ops){.op = &pb, .op_name = "pb"};
	ops[5] = (t_ops){.op = &ra, .op_name = "ra"};
	ops[6] = (t_ops){.op = &rb, .op_name = "rb"};
	ops[7] = (t_ops){.op = &rr, .op_name = "rr"};
	ops[8] = (t_ops){.op = &rra, .op_name = "rra"};
	ops[9] = (t_ops){.op = &rrb, .op_name = "rrb"};
	ops[10] = (t_ops){.op = &rrr, .op_name = "rrr"};
}
