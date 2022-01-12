/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:23:39 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/12 18:23:57 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTER_H
# define SORTER_H

typedef struct s_sort
{
	t_list	*sorted_list;
	t_list	*the_list;
	t_list	*paths;
}	t_sort;

#endif
