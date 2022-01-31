/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:23:56 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/31 17:57:21 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RULES_H
# define RULES_H

# include "stacks.h"

typedef const char *(*t_rule)(t_stacks *);

t_rule	get_rule_swap_here(void);
t_rule	get_rule_default_rotate_in_the_void(void);

#endif
