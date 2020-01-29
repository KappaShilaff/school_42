#include <unistd.h>
#include <stdarg.h>

int		ft_printf(const char *format, ...)
{
	va_list	lol;
	va_start(lol, format);
	int	i;

	i = 0;
	write(1, format, 3);
	write(1, va_arg(lol, char *), 3);
	return (0);
}
