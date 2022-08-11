/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 23:28:02 by yxu               #+#    #+#             */
/*   Updated: 2022/08/11 23:28:07 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	skip_space(char *str, int *seq)
{
	char	c;

	while (str[*seq])
	{
		c = str[*seq];
		if (c == ' ' || c == '\n' || c == '\r')
			(*seq)++;
		else if (c == '\f' || c == '\t' || c == '\v')
			(*seq)++;
		else
			break ;
	}
	return (*seq);
}

int	is_pos(char *str, int *seq)
{
	int	pos;

	pos = 1;
	while (str[*seq])
	{
		if (str[*seq] == '-')
		{
			pos = -pos;
			(*seq)++;
		}
		else if (str[*seq] == '+')
			(*seq)++;
		else
			break ;
	}
	return (pos);
}

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
				return (0);
		}
		existing[i] = *(str++);
		output++;
	}
	return (output);
}

int	char2int(char *str, int *seq, char *base, int base_system)
{
	int	i;
	int	result;

	result = 0;
	while (str[*seq])
	{
		i = 0;
		while (base[i])
		{
			if (base[i] == str[*seq])
			{
				result = result * base_system + i;
				break ;
			}
			i++;
		}
		if (base[i] == '\0')
			return (result);
		(*seq)++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	seq;
	int	pos;
	int	base_system;
	int	result;

	seq = 0;
	skip_space(str, &seq);
	pos = is_pos(str, &seq);
	base_system = cal_base_system(base);
	if (base_system < 2)
		return (0);
	result = char2int(str, &seq, base, base_system);
	if (pos == -1)
		result = -result;
	return (result);
}
