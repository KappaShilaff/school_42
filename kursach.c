#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <gmp.h>
#define uint128_t unsigned __int128

char *ft_itoa(uint128_t n);
uint128_t ft_atoi(char const *str);

uint128_t powmod(uint128_t a, uint128_t k, uint128_t n)
{

	mpz_t am, nm, bm;
	char	*str;

	mpz_init_set_str(am, ft_itoa(a), 10);
	mpz_init_set_str(nm, ft_itoa(n), 10);
	mpz_init_set_str(bm, "1", 10);
	while (k) {
		if (k % 2==0) {
			k /= 2;
			mpz_mul(am, am, am);
			mpz_fdiv_r(am, am, nm); 
		}
		else {
			k--;
			mpz_mul(bm, bm, am);
			mpz_fdiv_r(bm, bm, nm);
		}
	}
	str = malloc(100);
	mpz_get_str(str, 10, bm);
	return (ft_atoi(str));
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
		x = powmod(a, t, n);
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
