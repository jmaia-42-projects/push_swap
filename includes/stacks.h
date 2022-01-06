/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:43:41 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/06 18:38:26 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include "libft.h"

typedef struct s_stacks
{
	t_list	*stack_a;
	t_list	*stack_b;
}	t_stacks;

typedef struct s_stack
{
	t_list	stack;
}	t_stack;

t_stacks	*get_stacks(t_list *stack_a, t_list *stack_b);
int			push_elem(t_list **stack, int elem);

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
