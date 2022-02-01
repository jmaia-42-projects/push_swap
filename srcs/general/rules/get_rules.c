/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 21:54:14 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/01 11:19:13 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

t_rule	*get_rules()
{
	t_rule	*rules;

	rules = malloc(sizeof(*rules) * 6);
	if (!rules)
		return (0);
	rules[0] = get_rule_bubble_merge();
	rules[1] = get_rule_hide_and_seek_merge();
	rules[2] = get_rule_swap_here();
	rules[3] = get_rule_default_escape_from_b();
	rules[4] = get_rule_default_rotate_in_the_void();
	rules[5] = 0;
	return (rules);
}
