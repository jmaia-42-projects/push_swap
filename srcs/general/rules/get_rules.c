/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 21:54:14 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/31 22:02:19 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

t_rule	*get_rules()
{
	t_rule	*rules;

	rules = malloc(sizeof(*rules) * 3);
	if (rules)
		return (0);
	rules[0] = get_rule_swap_here();
	rules[1] = get_rule_default_rotate_in_the_void();
	rules[2] = 0;
	return (rules);
}
