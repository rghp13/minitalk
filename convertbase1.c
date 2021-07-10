/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertbase1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:11:08 by rponsonn          #+#    #+#             */
/*   Updated: 2021/07/10 16:45:57 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"


static int		ft_errorcheck(char *base)
{
	int i;
	int c;
	int	strlen;

	i = 0;
	if ((strlen = ft_strlen(base)) < 2)
		return (1);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (1);
		if (base[i] >= '\t' && base[i] <= '\r')
			return (1);
		i++;
	}
	i = 0;
	while (i < strlen)
	{
		c = i + 1;
		while (base[c])
			if (base[i] == base[c++])
				return (1);
		i++;
	}
	return (0);
}

static char	*ft_convert_result(int *array, char *base, int i, int flag)
{
	int		c;
	char	*ptr;

	c = 0;
	if (!(ptr = malloc(sizeof(char) * i + flag + 2)))
		return (NULL);
	if (flag)
		ptr[c++] = '-';
	while (i >= 0)
		ptr[c++] = base[array[i--]];
	ptr[c] = '\0';
	return (ptr);
}

static char	*ft_putnbr_base(long int nbr, char *base)
{
	int		base_len;
	int		i;
	int		neg;
	int		array[32];
	char	*ptr;

	base_len = ft_strlen(base);
	i = 0;
	neg = 0;
	if (nbr == 0)
		array[i++] = 0;
	if (nbr < 0)
		nbr = -nbr + neg++;
	while (nbr > 0)
	{
		array[i++] = nbr % base_len;
		nbr /= base_len;
	}
	ptr = ft_convert_result(array, base, --i, neg);
	return (ptr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	char	*ptr;

	if (ft_errorcheck(base_from) || ft_errorcheck(base_to))
		return (NULL);
	num = ft_atoi_base(nbr, base_from);
	ptr = ft_putnbr_base(num, base_to);
	return (ptr);
}