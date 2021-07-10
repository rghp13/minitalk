/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:26:36 by rponsonn          #+#    #+#             */
/*   Updated: 2021/07/10 18:22:04 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

/*
**a.out 12345 "hello world"
**send message
**get confirm
**print confirm
**end program
*/

int	main(int argc, char **argv)
{
	pid_t	s_pid;
	char	*binary;

	if (argc != 3)
		return (-1);
	s_pid = ft_atoi(argv[1]);
	binary = ft_conv_bin(argv[2]);
	printf("%s\n", binary);
	free(binary);
}
void	ft_conv_free(char *ptr1, char *ptr2, char *ptr3)
{
	free(ptr1);
	free(ptr2);
	free(ptr3);
}

char	*ft_conv_bin(char *src)
{
	char	*val;
	char	*binstr;
	char	*output;
	char	*temp;
	int	i;

	i = 0;
	if (src[i])
	{
		val = ft_convert_val_to_str((char)src[i++]);
		output = ft_convert_base(val, BASE10, BASE2);
		free(val);
	}
	while (src[i])
	{
		val = ft_convert_val_to_str(src[i++]);
		binstr = ft_convert_base(val, BASE10, BASE2);
		temp = ft_strjoin(output, binstr);
		ft_conv_free(val, binstr, output);
		output = temp;
	}
	return (output);
}
//TODO: MAKE SURE THAT BINARY CONVERSION ARE ALWAYS 8BIT

char	*ft_convert_val_to_str(char val)
{
	char *stringval;

	stringval = ft_itoa((int)val);
	return (stringval);
}