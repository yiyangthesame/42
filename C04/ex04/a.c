/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 23:27:57 by yxu               #+#    #+#             */
/*   Updated: 2022/08/11 23:28:06 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	cal_base_system(char *str)
{
	char	existing[64] = " +-";
	int		i;
	int		output;

	output = 0;
	while (*str != '\0')
	{
		i = 0;
		while (existing[i])
		{
			if (existing[i++] == *str)
				return 0;
		}
		existing[i] = *(str++);
		output++;
	}
	return (output);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb, int divisor, char *base)
{
	unsigned int	n;

	if (nb < 0)
	{
		ft_putchar('-');
		n = -nb;
	}
	else
		n = nb;
	if (n >= divisor)
		ft_putnbr(n / divisor, divisor, base);
	ft_putchar(base[n % divisor]);
}

void ft_putnbr_base(int nbr, char *base)
{
	int	divisor;

	divisor = cal_base_system(base);
	if (divisor >= 2)
		ft_putnbr(nbr, divisor, base);
	else
		return;
}

int	main(void)
{
	ft_putnbr_base(128, "01234567");
}
