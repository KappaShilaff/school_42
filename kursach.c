#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define uint128_t unsigned __int128

int		ft_numlen2(uint128_t t)
{
	int		i;

	i = 0;
	while (t /= 2)
		i++;
	return (i);
}


char	*ft_2(uint128_t t)
{
	char	*str;
	int		i;

	i = ft_numlen2(t);
	str = malloc(i + 1);
	str[i--] = '\0';
	while (t)
		{
			str[i--] = t % 2 + '0';
			t /= 2;
		}
	return (str);
}

uint128_t	ft_pow(uint128_t a, uint128_t t, uint128_t n)
{
	uint128_t tmp;
	char	*str;
	int		i;
	
	tmp = a;
	i = 1;
	str = ft_2(t);
	a = a % n;
	while (str[i])
	{
		if (str[i] == '0')
			a = (a * a) % n;
		if (str[i] == '1')
			a = (tmp * a * a) % n;
		i++;
	}
	return (a);
}

uint128_t ft_random(const uint128_t min, const uint128_t max) 
{
    return (rand() % (max - min + 1) + min);
}

int		ft_miller_rabin(uint128_t n, int k)
{
	int			i;
	uint128_t	t, s, x, a;

	s = 0;
	t = n - 1;
	while (t % 2 == 0)
	{
		t /= 2;
		s++;
	}
	while (k-- > 0)
	{
		a = ft_random(2, n - 2);
		x = ft_pow(a, t, n);
		if (x != 1 && x != n - 1)
		{
			i = s - 1;
			while (i-- > 0 && (x != n - 1))
			{
				x = (x * x) % n;
				if (x == 1)
					return (0);
			}
			if (x != n - 1 || i == 0)
				return (0);
		}
	}
	return (1);
}
uint128_t ft_atoi(char const *str)
{
	uint128_t		result;
	uint128_t		i;

	result = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	return (result);
}

int		ft_numlen(uint128_t n)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(uint128_t n)
{
	char	*str;
	int		i;

	if (n == 0)
		return ("0");
	i = ft_numlen(n);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = '\0';
	while (n != 0)
	{
		i--;
		str[i] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

int		ft_small(uint128_t n, int *prime)
{
	int		i;

	i = 0;
	while (i < 24)
	{
		if ((n % prime[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}


int		main(int ac, char *av[])
{
	uint128_t		s;
	uint128_t		r;
	uint128_t		n;
	int				prime[25];
	int				i;
	int				tmp;

	prime[0]	= 2;
	prime[1]	= 3;
	prime[2]	= 5;
	prime[3]	= 7;
	tmp			= 4;
	i			= 7;

	while (i++ < 100)
		if ((i % 2) && (i % 3) && (i % 5) && (i % 7))
			prime[tmp++] = i;
	s = ft_atoi(av[1]);
	while (1)
	{
		r = ft_random(s + 1, 4 * s + 2);
		n = 1 + s * r;
		if (s * s + s + 1 <= n && n <= 4 * s * s + 2 * s + 1)
		{
			if (ft_small(n, prime))
			{
				if (ft_miller_rabin(n, 5))
				{
					printf("%s\n", ft_itoa(n));
					return (0);
				}
			}
		}
	}
	return (0);
}
