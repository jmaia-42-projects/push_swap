/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:46:11 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/07 21:24:12 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_sorting.h"

static void	read_ops(t_dynamic_buffer *buf);
static int	apply_ops(t_stacks *stacks, t_dynamic_buffer *buf);
static int	is_lst_sorted(t_list *lst);
static int	intcmp(void *a, void *b);

int	check_sorting(t_stacks *stacks)
{
	t_dynamic_buffer	trash;
	t_dynamic_buffer	*buf;
	int					err;
	int					is_sorted;

	trash = get_buffer(sizeof(char *));
	buf = &trash;
	read_ops(buf);
	err = !apply_ops(stacks, buf);
	if (err)
		return (0);
	is_sorted = is_lst_sorted(stacks->stack_a->lstpp->begin);
	if (is_sorted && !stacks->stack_b->lstpp->begin)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_buffer(&buf, &free);
	return (1);
}

static void	read_ops(t_dynamic_buffer *buf)
{
	char	*newline_ptr;
	char	*line;

	line = get_next_line(0);
	while (line != 0)
	{
		newline_ptr = ft_strchr(line, '\n');
		if (newline_ptr)
			*newline_ptr = 0;
		append(buf, &line);
		line = get_next_line(0);
	}
}

static int	apply_ops(t_stacks *stacks, t_dynamic_buffer *buf)
{
	unsigned long		i;
	char				*raw_op;
	t_ops				op;

	i = 0;
	while (i < buf->i)
	{
		raw_op = *(char **)get_elem_ptr(buf, i);
		op = get_op(raw_op);
		if (!op.op)
			return (0);
		op.op(stacks);
		i++;
	}
	return (1);
}

static int	is_lst_sorted(t_list *lst)
{
	t_list	*sorted_list;
	int		is_sorted;

	sorted_list = ft_lstsort(lst, &intcmp);
	is_sorted = ft_lstequals(lst, sorted_list);
	ft_lstclear(&sorted_list, 0);
	return (is_sorted);
}

static int	intcmp(void *a, void *b)
{
	return (*(int *)a - *(int *)b);
}
