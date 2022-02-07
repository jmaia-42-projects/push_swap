/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inv_op_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:35:44 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/21 15:46:42 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INV_OP_UTILS_H
# define INV_OP_UTILS_H

# include "ops.h"
# include "libft.h"
# include "inv_ops.h"

const char	*get_inv_op_of(const char *op);
void		init_inv_ops(t_ops inv_ops[11]);

#endif
