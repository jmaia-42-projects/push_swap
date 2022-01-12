/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:21:01 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/05 17:48:37 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnbr(char *nbr)
{
	int	i;
	int	has_digits;

	i = 0;
	has_digits = 0;
	while (ft_isspace(nbr[i]))
		i++;
	if (nbr[i] == '+' || nbr[i] == '-')
		i++;
	while (ft_isdigit(nbr[i]))
	{
		has_digits = 1;
		i++;
	}
	if (nbr[i] == 0 && has_digits)
		return (1);
	return (0);
}
