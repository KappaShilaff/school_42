#include <unistd.h>
#include <stdarg.h>

int		ft_flag(char *str)
{
	int		i;
	while (*str == ' ' && *str)
		*str++;
	if (!*str)
		return (0);
	if 

ft_printnum(const char *str)
{
	size_t		i;
	size_t		n;

	n = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] = '%' && ft_)
		{
			i++;;
			n++;
		}
		i++;
	}
	return (n);
}

int		ft_printf(const char *format, ...)
{
	size_t	num;
	va_list	arg;
	int		i;

	num = ft_printnum(format);
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			*format++;
			if (i = ft_flag(*format))
			{
				*format++;
				ft_print((void)arg, i);
				va_arg(arg, 1);
			}
		}
		if (*format)
			write(1, &(*format++), 1);
	}
	return (0);
}
