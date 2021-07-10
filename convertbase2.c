/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertbase2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 16:30:37 by rponsonn          #+#    #+#             */
/*   Updated: 2021/07/10 16:46:54 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

static int			ft_str_val(char src, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (src == base[i])
			break ;
		i++;
	}
	return (i);
}

static int			ft_is_valid_base(char src, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (src == base[i])
			return (1);
		i++;
	}
	return (0);
}

static long int	ft_treat_string(char *str, int *base_length, char *base)
{
	int			i;
	int			neg;
	long int	hold;
	int			ret;

	i = 0;
	neg = 0;
	ret = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	while (ft_is_valid_base(str[i], base))
	{
		hold = ft_str_val(str[i++], base);
		ret *= *base_length;
		ret += hold;
	}
	if (neg % 2)
		ret = -ret;
	return (ret);
}

int			ft_atoi_base(char *str, char *base)
{
	int	basenum;
	int	base_length;

	base_length = 0;
	while (base[base_length])
		base_length++;
	basenum = ft_treat_string(str, &base_length, base);
	return (basenum);
}