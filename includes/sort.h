/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:15:01 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/12 18:25:45 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "libft.h"

# include "stacks.h"
# include "sorter.h"
# include "find_path.h"
# include "print_path.h"

void	print_sort(t_stacks *stacks);
void	free_sorter(t_sort **sorter);

#endif
