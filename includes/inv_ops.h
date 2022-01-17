/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inv_ops.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:49:01 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/17 15:52:23 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INV_OPS_H
# define INV_OPS_H

# include "stacks.h"

void	inv_ss(t_stacks *stacks);
void	inv_sa(t_stacks *stacks);
void	inv_sb(t_stacks *stacks);

void	inv_pa(t_stacks *stacks);
void	inv_pb(t_stacks *stacks);

void	inv_rr(t_stacks *stacks);
void	inv_ra(t_stacks *stacks);
void	inv_rb(t_stacks *stacks);

void	inv_rrr(t_stacks *stacks);
void	inv_rra(t_stacks *stacks);
void	inv_rrb(t_stacks *stacks);

#endif
