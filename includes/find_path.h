/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:36:01 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/29 17:23:10 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_PATH_H
# define FIND_PATH_H

# include "libft.h"

# include "stacks.h"
# include "sorter.h"
# include "path.h"
# include "inv_ops.h"
# include "inv_op_utils.h"
# include "ops.h"

t_path	*find_path(t_sort *sorter, t_stacks *stacks);
#endif
