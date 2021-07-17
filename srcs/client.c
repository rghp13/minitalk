/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:26:36 by rponsonn          #+#    #+#             */
/*   Updated: 2021/07/15 11:56:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
**a.out 12345 "hello world"
**send message
**get confirm
**print confirm
**end program
*/

int	main(int argc, char **argv)
{
	struct sigaction sa;
	pid_t	s_pid;
	int i;
	int k;

	sa.sa_sigaction =  ft_handler;
	(void)sa;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	k = 2;
	if (argc < 3)
		return (-1);
	s_pid = ft_atoi(argv[1]);
	while (k < argc)
	{
		i = 0;
		while (argv[k][i])
		{
			ft_bit_check(argv[k][i++], s_pid);
		}
		ft_bit_check('\0', s_pid);
		k++;
	}
	return (0);
}

void	ft_handler(int sig, siginfo_t *si, void *arg)
{
	(void)sig;
	(void)si;
	(void)arg;
	write(1, "Message was received\n", 21);
}

void	ft_bit_check(unsigned char bit, pid_t s_pid)
{
	int bitmask;

	bitmask = 0b10000000;
	while (bitmask)
	{
		if (bit & bitmask)
			kill(s_pid, SIGUSR2);
		else
			kill(s_pid, SIGUSR1);
		usleep(100);//play with this to change the send speed
		bitmask = bitmask >> 1;
	}
}