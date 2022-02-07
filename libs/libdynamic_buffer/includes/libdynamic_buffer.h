/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdynamic_buffer.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:13:51 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/07 17:35:20 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBDYNAMIC_BUFFER_H
# define LIBDYNAMIC_BUFFER_H
# include <stddef.h>

typedef struct s_dynamic_buffer
{
	void			*buffer;
	unsigned long	i;
	unsigned long	len;
	size_t			elem_size;
}	t_dynamic_buffer;

t_dynamic_buffer	get_buffer(size_t elem_size);
int					free_buffer(t_dynamic_buffer **buffer, void (*del)(void *));
int					append(t_dynamic_buffer *buffer, void *elem);
void				*get_elem_ptr(t_dynamic_buffer *buffer, unsigned long i);
int					adjust(t_dynamic_buffer *buffer);
char				*as_str(t_dynamic_buffer *buffer);
#endif
