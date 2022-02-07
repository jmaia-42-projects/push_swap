/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_general.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:00:39 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/03 17:04:18 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_GENERAL_H
# define SORT_GENERAL_H

# include <unistd.h>

# include "stacks.h"
# include "print_stacks.h"
# include "push_below_median.h"
# include "push_everything_but_2_lasts.h"
# include "push_back_to_A_sorted_way.h"
# include "rotate_until_sorted.h"

void	print_sort_general(t_stacks *stacks);

#endif
