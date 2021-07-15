/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:04:23 by rponsonn          #+#    #+#             */
/*   Updated: 2021/07/15 12:19:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_array buffer;

int main(void)
{
	struct sigaction sa;

	ft_init();
	ft_convert_pid_str();
	(void)sa;
	sa.sa_sigaction = &ft_store_bit;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	//signal(SIGUSR1, ft_store_bit);
	//signal(SIGUSR2, ft_store_bit);
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

	mask = 0b10000000 >> buffer.bit;
	if (sigval == 1)
		buffer.buff[buffer.count] = buffer.buff[buffer.count] | mask;
	buffer.bit++;
	if (buffer.bit > 7)
	{
		buffer.count++;
		buffer.bit = 0;
		ft_check_null();//don't need an if here anymore
	}
	return (0);
}

/*
**Separate buffer count from null check
**Also reduce the buffer count size because write needs extra space
*/

int	ft_check_null(void)
{
	if (buffer.buff[buffer.count - 1] == '\0')//triggers on null terminator, clean for next use and send signal. Is first in case I get null term on the 98th char
	{
		ft_write_buffer();
		ft_init();
		kill(buffer.pid, SIGUSR1);
		//return (1);
	}
	else if (buffer.count >= 98)//triggers on too many chars, wipes buffer and resets for more uses, reduced from 100 to 98 for edge case protections
	{
		write(1,buffer.buff, ft_strlen(buffer.buff));//best to strlen instead of trust the count
		ft_init();
		//return (1);
	}
	return (0);
}

/*
**Rework this because we only want a newline if the null check passes
*/

int	ft_write_buffer(void)//going to do a separate write for the newline. it only triggers at the end of signal sequence so it shouldn't take up too much time.
{
	write(1, buffer.buff, ft_strlen(buffer.buff));
	write(1, "\n", 1);
	return (0);
}
