/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_to_the_top.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:18:27 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/07 14:37:16 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRING_TO_THE_TOP_H
# define BRING_TO_THE_TOP_H

# include <unistd.h>

# include "stacks.h"
# include "get_double_distance_of.h"
# include "ops.h"

void	bring_to_the_top(t_stacks *stacks, int elems[2]);

#endif
