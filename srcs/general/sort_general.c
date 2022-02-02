/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:02:17 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/02 22:56:32 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_general.h"

static int	has_more_than_3_elems(t_stack *stack);
static int	get_median(t_list *list);

void	print_sort_general(t_stacks *stacks)
{
	t_list	*cur;
	int		elem_n;
	int		i;

	elem_n = ft_lstsize(stacks->stack_a->lstpp->begin);
	while (i < elem_n / 2)
	(void) stacks;
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
	cur = list;
	while (i < lst_size / 2)
		cur = cur->next;
	median = *(int *)cur->content;
	ft_lstclear(sorted_list, 0);
	return (*(int *)cur->content);
}

static int	has_more_than_3_elems(t_stack *stack)
{
	return (stack->lstpp->begin && stack->lstpp->begin->next
			&& stack->lstpp->begin->next->next);
}
