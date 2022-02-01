/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 21:54:14 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/01 11:50:20 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

t_rule	*get_rules()
{
	t_rule	*rules;
	int		i;

	rules = malloc(sizeof(*rules) * 8);
	if (!rules)
		return (0);
	i = 0;
	rules[i++] = get_rule_bubble_move();
	rules[i++] = get_rule_bubble_merge();
	rules[i++] = get_rule_hide_and_seek_merge();
	rules[i++] = get_rule_swap_here();
	rules[i++] = get_rule_push_to_sort();
	rules[i++] = get_rule_default_escape_from_b();
	rules[i++] = get_rule_default_rotate_in_the_void();
	rules[i++] = 0;
	return (rules);
}
