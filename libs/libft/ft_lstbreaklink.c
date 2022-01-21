/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstbreaklink.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:37:28 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/20 22:08:46 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstbreaklink(t_list *left_node, t_list *right_node)
{
	if (!left_node || !right_node)
		return ;
	left_node->next = 0;
	right_node->previous = 0;
}
