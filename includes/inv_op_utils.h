/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inv_op_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:35:44 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/31 22:19:35 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INV_OP_UTILS_H
# define INV_OP_UTILS_H

# include "op.h"
# include "libft.h"
# include "inv_ops.h"

const char	*get_inv_op_of(const char *op);
void		init_inv_ops(t_op inv_ops[11]);

#endif
