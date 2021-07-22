/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:04:23 by rponsonn          #+#    #+#             */
/*   Updated: 2021/07/22 17:15:04 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_array	g_buffer;

int	main(void)
{
	struct sigaction	sa;

	ft_init();
	ft_convert_pid_str();
	(void)sa;
	sa.sa_sigaction = &ft_store_bit;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		usleep(100);
	return (0);
}

void	ft_init(void)
{
	g_buffer.bit = 0;
	g_buffer.count = 0;
	ft_memset(g_buffer.buff, 0, BUFFSIZE);
}

int	ft_add_bit(int sigval)
{
	char	mask;

	mask = 0b10000000 >> g_buffer.bit;
	if (sigval == 1)
		g_buffer.buff[g_buffer.count] = g_buffer.buff[g_buffer.count] | mask;
	g_buffer.bit++;
	if (g_buffer.bit > 7)
	{
		g_buffer.count++;
		g_buffer.bit = 0;
		ft_check_null();
	}
	return (0);
}

/*
**Separate g_buffer count from null check
**Also reduce the g_buffer count size because write needs extra space
*/

int	ft_check_null(void)
{
	if (g_buffer.buff[g_buffer.count - 1] == '\0')
	{
		write(1, g_buffer.buff, ft_strlen(g_buffer.buff));
		write(1, "\n", 1);
		ft_init();
		kill(g_buffer.pid, SIGUSR1);
	}
	else if (g_buffer.count >= (BUFFSIZE - 2))
	{
		write(1, g_buffer.buff, ft_strlen(g_buffer.buff));
		ft_init();
	}
	return (0);
}
