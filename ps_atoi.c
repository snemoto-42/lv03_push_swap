/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:17:37 by snemoto           #+#    #+#             */
/*   Updated: 2023/04/24 17:08:49 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n' \
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

static int	check_sign(const char *str)
{
	if (*str == '-')
		return (-1);
	return (1);
}

static int	check_int(unsigned long ret, const char str, int sign)
{
	unsigned int	div;
	unsigned int	mod;

	div = INT_MAX / 10;
	mod = INT_MAX % 10;
	if (sign == -1)
		mod++;
	if ((ret > div && str) \
		|| (ret == div && (unsigned long)(str - '0') > mod))
		return (sign);
	return (0);
}

int	ps_atoi(const char *str)
{
	unsigned long	ret;
	int				sign;

	ret = 0;
	while (ft_isspace(*str))
		str++;
	sign = check_sign(str);
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		if (check_int(ret, *str, sign) != 0)
			return (0);
		ret = ret * 10 + (*str++ - '0');
	}
	return ((int)(sign * ret));
}
