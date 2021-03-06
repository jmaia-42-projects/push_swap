/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:02:17 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/08 11:02:39 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_general.h"

void	print_sort_general(t_stacks *stacks)
{
	if (ft_lstis_sorted(stacks->stack_a->lstpp->begin))
		return ;
	push_below_median(stacks);
	push_everything_but_2_lasts(stacks);
	push_back_to_a_sorted_way(stacks);
	rotate_until_sorted(stacks);
}
