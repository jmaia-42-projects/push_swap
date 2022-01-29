/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_series_strength.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:57:27 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/29 22:36:36 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_series_strength.h"

static void	fill_series(t_stack *stack, int *strengths, int n_elems);
static int	are_following(t_list *node1, t_list *node2, int n_elems);
static void	update_strengths(int *strengths, int strength);

int	*get_series_strength(t_stacks *stacks)
{
	int	*strengths;

	strengths = malloc(sizeof(int) * 5);
	ft_memset(strengths, 0, sizeof(int) * 5);
	fill_series(stacks->stack_a, strengths, stacks->n_elems);
	return (strengths);
}

static void	fill_series(t_stack *stack, int *strengths, int max)
{
	int		cur_len;
	t_list	*cur;
	t_list	*fake_cur_next;

	cur_len = 1;
	cur = stack->lstpp->begin;
	while (cur)
	{
		if (cur->next)
			fake_cur_next = cur->next;
		else
			fake_cur_next = stack->lstpp->begin;
		if (are_following(cur, fake_cur_next, max))
			cur_len++;
		else
		{
			update_strengths(strengths, cur_len);
			cur_len = 1;
		}
		cur = cur->next;
	}
}

static void	update_strengths(int *strengths, int strength)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < 5)
	{
		if (strength > strengths[i])
		{
			tmp = strengths[i];
			strengths[i] = strength;
			strength = tmp;
		}
		i++;
	}
}

static int	are_following(t_list *node1, t_list *node2, int max)
{
	int	are_really_following;
	int	are_end_start_following;

	are_really_following = *(int *)node2->content == *(int *)node1->content + 1;
	are_end_start_following = *(int *)node1->content == max && *(int *)node2->content == 1;
	return (are_really_following || are_end_start_following);
}
