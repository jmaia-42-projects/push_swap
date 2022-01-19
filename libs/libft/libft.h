/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:50:43 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/19 16:29:50 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>

// Libc functions
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isspace(char c);
size_t			ft_strlen(const char *s);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_atoi(const char *nptr);
void			*ft_calloc(size_t nmembm, size_t size);
char			*ft_strdup(const char *s);

// Additional functions
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
unsigned char	*ft_itoa(long long n);
unsigned char	*ft_itoa_base(long long n, char *base);
unsigned char	*ft_uitoa_base(unsigned long long nbr, char *base);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_put_bytes_fd(char *s, unsigned int len, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

int				ft_isint(char *nbr);
int				ft_isnbr(char *nbr);
int				ft_strcmp(char *s1, char *s2);

typedef struct s_list
{
	void			*content;
	struct s_list	*previous;
	struct s_list	*next;
}	t_list;

typedef struct s_listpp
{
	t_list	*begin;
	t_list	*end;
}	t_listpp;

t_list	*ft_lstnew(void *content);
void	ft_lstset_next(t_list *lst, t_list *next);
void	ft_lstbreaklink(t_list *lst, t_list *next);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
			void (*del)(void *));
t_list	*ft_lstprevious(t_list *lst);
t_list	*ft_lstcpy(t_list *lst);
t_list	*ft_lstsort(t_list *lst, int (*cmp)(void *, void *));
int		ft_lstequals(t_list *lst1, t_list *lst2);

t_listpp	*ft_lstppnew(t_list *begin, t_list *end);
t_listpp	*ft_lstppcpy(t_listpp *lstpp);
t_listpp	*ft_lstppsort(t_list *lst, int (*cmp)(void *, void *));
void		ft_lstppadd_front(t_listpp *lstpp, t_list *new);
void		ft_lstppadd_back(t_listpp *lstpp, t_list *new);
void		ft_lstppclear(t_listpp **lstpp, void (*del)(void *));
#endif
