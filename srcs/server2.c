/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:04:23 by rponsonn          #+#    #+#             */
/*   Updated: 2021/07/12 19:00:07 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


int	ft_convert_pid_str(void)
{
	pid_t server_pid;
	char *pids;
	char *temp;

	server_pid = getpid();
	pids = ft_itoa(server_pid);
	temp = ft_strjoin("The Pid is = ", pids);
	write(1, temp, ft_strlen(temp));
	free(pids);
	free(temp);
	return (0);
}

int	ft_store_bit(int sig, siginfo_t *si, void *arg)
{
	(void)arg;
	if (si.si_signo == SIGUSR1)
		ft_add_bit(0);
	else if (si.si_signo == SIGUSR2)
		ft_add_bit(1);
	else
		exit(1);
}