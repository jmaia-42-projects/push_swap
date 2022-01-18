/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:43:41 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/17 23:31:03 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include <stdlib.h>
# include "libft.h"

typedef struct s_stack
{
	t_list	*list;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_stacks;

t_stack		*get_stack(void);

t_stacks	*get_stacks(t_stack *stack_a, t_stack *stack_b);
t_stacks	*clone_stacks(t_stacks *stacks);
int			push_elem(t_stack *stack, int elem);
void		free_stacks(t_stacks *stacks, int do_free_content);
void		free_stack(t_stack *stack, int do_free_content);

void		ss(t_stacks *stacks);
void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);

void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);

void		rr(t_stacks *stacks);
void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);

void		rrr(t_stacks *stacks);
void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);

#endif
