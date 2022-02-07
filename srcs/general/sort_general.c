/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:02:17 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/04 13:46:50 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_general.h"

#include <stdio.h>

void	print_sort_general(t_stacks *stacks)
{
	printf("Pushing everything below median...\n");
	push_below_median(stacks);
	print_stacks(stacks);
	printf("Pushing everything but 2 lasts...\n");
	push_everything_but_2_lasts(stacks);
	print_stacks(stacks);
	printf("Pushing back everything to a in a sorted way...\n");
	push_back_to_A_sorted_way(stacks);
	print_stacks(stacks);
	printf("Rotating until sorted...\n");
	rotate_until_sorted(stacks);
	print_stacks(stacks);
}
