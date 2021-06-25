#include "../ft_printf.h"

t_flags	*parse_input(char **input, va_list ap)
{
	t_flags	*flags;

	flags = ft_calloc(1, sizeof(t_flags));
	if (!flags)
		return (flags);
	*input = parse_flags(*input, flags);
	*input = parse_width(*input, flags, ap);
	*input = parse_precision(*input, flags, ap);
	*input = parse_cspdiuxX(*input, flags);
	return (flags);
}
