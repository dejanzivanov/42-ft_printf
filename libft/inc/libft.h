/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 21:52:43 by dzivanov          #+#    #+#             */
/*   Updated: 2021/07/02 00:30:02 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int			ft_otter(unsigned long stick, char *otter_pall);
int			ft_beaver(unsigned long tooth, int root);
char		**ft_split(char const *str, char delimiter);
int			ft_toupper(int c);
char		*ft_strtrim(char const *s1, char const *set);
void		ft_putchar_fd(char c, int fd);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
void		*ft_memset(void *str, int c, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_putendl_fd(char *s, int fd);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t len);
void		ft_putnbr_fd(int n, int fd);
char		*ft_strdup(const char *s);
int			ft_isdigit(int c);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strrchr(const char *str, int c);
void		ft_putstr_fd(char *s, int fd);
int			ft_isalnum(int c);
int			ft_atoi(const char	*str);
void		*ft_memcpy(void *dest, const void *src, size_t n);
int			ft_isalpha(int c);
char		*ft_strnstr(const char *str, const char *to_find, size_t len);
char		*ft_strchr(const char *str, int c);
int			ft_tolower(int c);
int			ft_isprint(int c);
void		*ft_memccpy(void *dest, const void *src, int c, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_bzero(void *s, size_t n);
int			ft_isascii(int c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_lstadd_front(t_list **lst, t_list *neew);
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *neew);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int			ft_numlen(long n);
char		*ft_uitoa(unsigned int nb);
int			ft_putchar(char c);
char		*ft_itoa_base(char *str, unsigned long n, int base, int c);

#endif
