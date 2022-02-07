/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:23:14 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/03 12:45:39 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	char	*cur;
	int		result;
	int		sign;
	int		digit;

	result = 0;
	cur = (char *)nptr;
	sign = 0;
	while (ft_isspace(*cur))
		cur++;
	if (*cur == '+' || *cur == '-')
	{
		sign = *cur == '-';
		cur++;
	}
	while (ft_isdigit(*cur))
	{
		digit = *cur - '0';
		result = result * 10 + digit;
		cur++;
	}
	return (result * (-2 * sign + 1));
}
