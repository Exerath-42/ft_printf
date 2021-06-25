#include "ft_printf.h"

static void	without_flags(int *count, char **input)
{
	ft_putchar(**input);
	(*count)++;
	(*input)++;
}

static void	with_flags(int *count, char **input, va_list ap)
{
	int	tmp_count;

	tmp_count = parse(ap, input);
	(*count) += tmp_count;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	char	*input;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		input = (char *)format;
		if (*format != '%')
			without_flags(&count, &input);
		else
			with_flags(&count, &input, ap);
		format = input;
	}
	va_end(ap);
	return (count);
}
