/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:59:52 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/07 14:38:07 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPS_H
# define OPS_H

# include "stacks.h"

typedef struct s_ops
{
	void		(*op)(t_stacks *);
	const char	*op_name;
}	t_ops;

#endif
