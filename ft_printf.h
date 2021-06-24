#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int		zero;
	int		minus;
	int		sign;
	int		width;
	int		precision;
	int		precision_failed;
	int		dot;
	int		conversion;
	void	*data;
	int		pure_width;
	int		failed;
}	t_flags;

int			ft_printf(const char *format, ...);

int			parse(va_list ap, char **input);
t_flags		*parse_input(char **input, va_list ap);
char		*parse_flags(char *tmp, t_flags *flags);
char		*parse_width(char *tmp, t_flags *flags, va_list ap);
char		*parse_precision(char *tmp, t_flags *flags, va_list ap);
char		*parse_cspdiuxX(char *tmp, t_flags *flags);

void		*read_value(int conv, va_list ap);
void		*read_int(va_list ap);
void		*read_string(va_list ap);
void		*read_pointer(va_list ap);
void		*read_unsigned(va_list ap);
void		*read_percent(void);

int			count_width(int mode, void *data);
int			count_digits(int num);
int			count_unsigned_base(unsigned num, unsigned base);
int			count_digits_ptr(void *ptr);

void		ft_alignment(t_flags *flags, int spaces);
void		ft_putstr(char *str);
void		ft_putnbr_base(unsigned nb, unsigned base, char mode);
int			convert(int c, int mode);
int			ft_negative_check(int n);
void		ft_putstr_custom(char *s, int n);
void		ft_putptr(void	*ptr);
void		ft_putnbr(int nb);
int			min(int a, int b);
int			max(int a, int b);
void		fill_str(int c, int n);
void		ft_putchar(char c);
int			is_it_in(char c, const char *str);

int			print(t_flags *flags);
int			print_int(t_flags *flags);
int			print_unsigned(t_flags *flags, unsigned int base, char mode);
int			print_char(t_flags *flags);
int			print_string(t_flags *flags);
int			print_pointer(t_flags *flags);

#endif
