/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inv_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:54:50 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/17 15:59:53 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inv_ops.h"

void	inv_rr(t_stacks *stacks)
{
	rrr(stacks);
}

void	inv_ra(t_stacks *stacks)
{
	rra(stacks);
}

void	inv_rb(t_stacks *stacks)
{
	rrb(stacks);
}
