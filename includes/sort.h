/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:15:01 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/21 16:59:27 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "libft.h"

# include "stacks.h"
# include "sorter.h"
# include "find_path.h"
# include "print_path.h"

void	print_sort_less_six(t_stacks *stacks);
void	free_sorter(t_sort **sorter);

#endif
