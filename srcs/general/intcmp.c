/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 22:34:35 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/31 22:35:17 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intcmp.h"

int	intcmp(void *v1, void *v2)
{
	int	*i1;
	int	*i2;

	i1 = v1;
	i2 = v2;
	return (*i1 - *i2);
}
