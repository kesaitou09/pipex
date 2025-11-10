/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:47:32 by kesaitou          #+#    #+#             */
/*   Updated: 2025/10/18 20:45:59 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# define SUCCESS 1
# define ERROR -1

typedef struct s_info
{
	unsigned char	flags;
	size_t			width;
	int				precision;
	char			specifier;
	int				total_len;
}					t_info;

typedef enum e_flag
{
	F_MINUS = 1 << 0,
	F_PLUS = 1 << 1,
	F_SPACE = 1 << 2,
	F_ZERO = 1 << 3,
	F_HASH = 1 << 4,
}					t_flag;

int					ft_printf(const char *format, ...);
int					print_hub(va_list *args, t_info *inf);
int					u_print_process(char *num_arr, t_info *inf, size_t hash,
						size_t zero);
int					s_print_process(char *num_arr, t_info *inf, size_t zero,
						int is_minus);
int					print_hash(t_info *inf, size_t hash);
size_t				count_len_ptr(uintptr_t num, size_t base_len);
int					p_print_process(char *num_arr, t_info *inf, size_t hash,
						size_t zero);
char				*ft_uptoa_base(void *ptr, const char *base);
int					print_cper(va_list *args, t_info *inf);
int					print_s(va_list *args, t_info *inf);
int					print_di(t_info *inf, va_list *args);
int					print_u(t_info *inf, va_list *args);
int					print_x(t_info *inf, va_list *args);
int					print_lx(t_info *inf, va_list *args);
int					print_p(va_list *args, t_info *inf, const char *base);

void				init_info(t_info *inf);
int					parse(const char **format, t_info *inf, va_list *args);
int					parse_hub(const char **format, t_info *inf, va_list *args);
void				parse_flag(const char **format, t_info *inf);
void				parse_specifi(const char **format, t_info *inf);
void				parse_precision(const char **format, t_info *inf);
void				parse_width(const char **format, t_info *inf);

char				*stoa_hub(va_list *args, const char *base, int *is_minus);
char				*ft_utoa_base(unsigned long long num, const char *base);
char				*utoa_hub(va_list *args, const char *base);
size_t				count_len(unsigned long long num, size_t base_len);
void				calc_maxlen(size_t *max_len, t_info *inf, const char *str);
void				calc_pad(size_t *pad, t_info *inf, size_t max_len);

int					put_nstr(const char *str, size_t n, t_info *inf);
int					put_nzero(t_info *inf, size_t n);
int					put_nspace(t_info *inf, size_t n);

int					put_space_sign(t_info *inf, size_t sign, int is_minus,
						size_t space);
int					right_align(t_info *inf, size_t pad);
int					ft_putchar(char c, t_info *inf);
int					ft_putstr(char *str, t_info *inf);
int					is_flag(char c);
int					ft_atoi_alpha(const char **nptr);
int					ft_strcmp(const char *s1, const char *s2);

#endif
