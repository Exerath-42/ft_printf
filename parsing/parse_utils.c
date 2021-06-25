#include "../ft_printf.h"

char	*parse_flags(char *input, t_flags *flags)
{
	while (*input == ' ')
	{
		flags -> empty = 1;
		input++;
	}
	if (flags -> empty == 1)
		ft_putchar(' ');
	while (is_it_in(*input, "-0"))
	{
		if (*input == '0')
			flags -> zero = 1;
		else if (*input == '-')
			flags -> minus = 1;
		input++;
	}
	return (input);
}

char	*parse_width(char *input, t_flags *flags, va_list ap)
{
	if (*input == '*')
	{
		flags -> width = va_arg(ap, int);
		if (flags -> width < 0)
		{
			flags -> width = ft_negative(flags -> width);
			flags -> minus = 1;
		}
		return (++input);
	}
	else
	{
		flags -> width = ft_atoi(input);
		if (ft_isdigit(*input))
			input += count_digits(flags -> width);
		return (input);
	}
}

static char 	*ft_zero_in_input_check(char *input, t_flags *flags)
{
	int	zero_in_input;

	zero_in_input = 0;
	if (*input == '0' && *(input + 1)
		&& *(input + 1) >= 48 && *(input + 1) <= 57)
		zero_in_input++;
	flags -> precision = ft_atoi(input);
	if (ft_isdigit(*input))
		input += count_digits(flags -> precision);
	input += zero_in_input;
	return (input);
}

char	*parse_precision(char *input, t_flags *flags, va_list ap)
{
	if (*input == '.')
	{
		flags -> dot = 1;
		input++;
		if (*input == '*')
		{
			flags -> precision = va_arg(ap, int);
			return (++input);
		}
		else
		{
			return (ft_zero_in_input_check(input, flags));
		}
	}
	return (input);
}

char	*parse_cspdiuxX(char *input, t_flags *flags)
{
	if (is_it_in(*input, "cspdiuxX%"))
	{
		flags -> conversion = *input;
		input++;
	}
	else
		flags -> failed = 1;
	return (input);
}
