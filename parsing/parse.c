#include "../ft_printf.h"

static void	free_tmp(t_flags *flags)
{
	free(flags -> data);
	free(flags);
}

static int	check_precision(int precision, int pure_width, t_flags *flags)
{
	if (precision < 0)
	{
		flags -> precision_failed = 1;
		return (pure_width);
	}
	return (precision);
}

int	parse(va_list ap, char **input)
{
	t_flags	*flags;
	int		res;

	(*input)++;
	flags = parse_input(input, ap);
	if (!flags)
		return (0);
	if (flags -> failed)
	{
		free_tmp(flags);
		return (0);
	}
	flags -> data = read_value(flags -> conversion, ap);
	if (!(flags -> data))
	{
		free_tmp(flags);
		return (0);
	}
	flags -> pure_width = count_width(flags -> conversion, flags -> data);
	flags -> precision = check_precision(flags -> precision,
			flags -> pure_width, flags);
	res = print(flags);
	free_tmp(flags);
	return (res);
}
