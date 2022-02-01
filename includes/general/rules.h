/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:23:56 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/01 11:14:54 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RULES_H
# define RULES_H

# include "stacks.h"
# include "op.h"

typedef t_op (*t_rule)(t_stacks *);

t_rule	*get_rules(void);

t_rule	get_rule_bubble_merge(void);
t_rule	get_rule_hide_and_seek_merge(void);
t_rule	get_rule_swap_here(void);
t_rule	get_rule_push_to_sort(void);
t_rule	get_rule_default_escape_from_b(void);
t_rule	get_rule_default_rotate_in_the_void(void);

#endif
