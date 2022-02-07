/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_below_median.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:31:38 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/07 10:43:39 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_below_median.h"

static int	get_median(t_list *list);
static int	intcmp(void *v1, void *v2);
static void	rotate_to_nearest_below_median(t_stacks *stacks, int median);

void	push_below_median(t_stacks *stacks)
{
	t_list	*cur;
	int		elem_n;
	int		i;
	int		median;

	elem_n = ft_lstsize(stacks->stack_a->lstpp->begin);
	cur = stacks->stack_a->lstpp->begin;
	median = get_median(stacks->stack_a->lstpp->begin);
	i = 0;
	while (i++ <= (int)(1.0 * elem_n / 2 - .5))
	{
		rotate_to_nearest_below_median(stacks, median);
		pb(stacks);
		write(1, "pb\n", 3);
	}
}	

static int	get_median(t_list *list)
{
	t_list	*sorted_list;
	int		lst_size;
	int		i;
	int		median;
	t_list	*cur;

	sorted_list = ft_lstsort(list, &intcmp);
	lst_size = ft_lstsize(sorted_list);
	i = 0;
	cur = sorted_list;
	while (i++ < lst_size / 2)
		cur = cur->next;
	median = *(int *)cur->content;
	ft_lstclear(&sorted_list, 0);
	return (median);
}

static int	intcmp(void *v1, void *v2)
{
	int	*i1;
	int	*i2;

	i1 = v1;
	i2 = v2;
	return (*i1 - *i2);
}

static void	rotate_to_nearest_below_median(t_stacks *stacks, int median)
{
	while (*(int *)stacks->stack_a->lstpp->begin->content > median)
	{
		write(1, "ra\n", 3);
		ra(stacks);
	}
}
