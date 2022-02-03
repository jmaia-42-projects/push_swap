/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:02:17 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/03 17:04:10 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_general.h"

void	print_sort_general(t_stacks *stacks)
{
	push_below_median(stacks);
	print_stacks(stacks);
	push_everything_but_2_lasts(stacks);
	print_stacks(stacks);
	push_back_to_A_sorted_way(stacks);
	rotate_until_sorted(stacks);
}
