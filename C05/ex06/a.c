/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 23:37:08 by yxu               #+#    #+#             */
/*   Updated: 2022/08/13 23:37:12 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	factor;

	if (nb == 0 || nb == 1)
		return (0);
	factor = 2;
	while (factor <= nb / 2)
	{
		if (nb % factor == 0)
			return (0);
		factor++;
	}
	return (1);
}

#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_is_prime(8));
}
