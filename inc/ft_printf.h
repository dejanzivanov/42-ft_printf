/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:55:51 by dzivanov          #+#    #+#             */
/*   Updated: 2021/06/30 20:50:01 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_print
{
	va_list		args;
	int			width;
	int			precision;
	int			zero;
	int			point;
	int			dash;
	int			total_length;
	int			sign;
	int			is_zero;
	int			percentage;
	int			space_flag;
}				t_print;

int		ft_printf(const char *format, ...);
int		ft_handler_width(t_print *tab, char const *format, int temp);
int		ft_handler_zero(t_print *tab, char const *format, int temp);
int		ft_handler_star(t_print *tab, char const *format, int temp);
int		ft_handler_dash(t_print *tab, char const *format, int temp);
int		ft_handler_precision(t_print *tab, char const *format, int temp);
int		ft_handle_variables(t_print *tab, const char *format, int temp);
void	ft_precision_checker(t_print *tab);
void	ft_width_checker(t_print *tab);
t_print	*ft_reset(t_print *tab);
t_print	*ft_init(t_print *tab);
int		ft_handle_format(t_print *tab, const char *format, int temp);
void	ft_print_char(t_print *tab);
int		ft_update_tab_string(char *str, t_print *tab, int len);
void	ft_update_tab(t_print *tab, int len);
void	ft_print_point(t_print *tab);
void	ft_print_string(t_print *tab);
int		ft_sign_checker(t_print *tab, int i);
void	ft_print_integer(t_print *tab);
void	ft_right_character_handler(t_print *tab, int len);
void	ft_left_character_handler(t_print *tab, int len);
void	ft_print_zero_point(t_print *tab);
void	ft_print_unsigned_int(t_print *tab);
void	ft_print_zero(t_print *tab);
void	ft_print_null_pointer(t_print *tab);
void	ft_right_zero_handler(t_print *tab);
void	ft_left_zero_handler(t_print *tab);
void	ft_left_duplicatex(t_print *tab);
void	ft_right_duplicatex(t_print *tab);
void	ft_print_pointer(t_print *tab);
void	ft_print_hexadecimal(t_print *tab, int c);
void	ft_print_percentage(t_print *tab);
int		ft_handler_space(t_print *tab, int temp);
int		ft_flag_checker(char c);

#endif
