#include "push_swap.h"

long	ft_atol(char *s)
{
	int	i;
	int	neg;
	long	number;

	i = 0;
	neg = 1;
	number = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s [i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			neg = -neg;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		number = number * 10 + s[i] - '0';
		i++;
	}
	if (((neg == 1 && number > INT_MAX) || (neg == -1 && - number < INT_MIN)))
			return (0);
	return (number * neg);
}
