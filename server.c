/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:04:23 by rponsonn          #+#    #+#             */
/*   Updated: 2021/07/12 16:20:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

t_array buffer;



int main(void)
{
	pid_t server_pid;
	char *pids;
	struct sigaction sa;

	ft_init();
	sa.sa_sigaction = ft_store_bit;
		ft_convert_pid_str();
	while (1)
		sleep(1);
	return (0);
}


void	ft_init(void)
{
	buffer.bit = 0;
	buffer.count = 0;
	ft_memset(buffer.buff, 0, 100);
}

int	ft_add_bit(int sigval)
{
	char mask;

	mask = 0b10000000;
	mask = mask >> buffer.bit;
	if (sigval == 1)
		buffer.buff[buffer.count] = buffer.buff[buffer.count] | mask;
	buffer.bit++;
	if (buffer.bit > 7)
	{
		if (ft_check_null() == 0)
		{
			buffer.bit = 0;
			buffer.count++;
		}
	}
	return (0);
}
int	ft_check_null(void)
{
	if (buffer.buff[buffer.count] == '\0' || buffer.count >= 99)
	{
		ft_write_buffer();
		ft_init();
		return (1);
	}
	return (0);
}

int	ft_write_buffer(void)
{
	int len;

	buffer.buff[buffer.count] = '\n';
	buffer.buff[buffer.count + 1] = '\0';
	len = ft_strlen(buffer.buff);
	write(1,buffer.buff, len);
	return (0);
}
