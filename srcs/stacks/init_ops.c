/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:15:23 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/29 17:28:22 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"

void	init_ops(t_ops ops[11])
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
