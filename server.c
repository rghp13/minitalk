/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:04:23 by rponsonn          #+#    #+#             */
/*   Updated: 2021/07/08 15:23:20 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

/*
**PERMITTED UNIX SIGNALS
**write
**signal
**sigemptyset
**sigaddset
**sigaction
**kill
**getpid
**malloc
**free
**pause
**sleep
**usleep
**exit
*/

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
	sigaction()
}

int main(void)
{
	pid_t server_pid;
	char *pids;
	struct sigaction sa;
	

	ft_convert_pid_str();
	while (1)
	{
		kill(getpid(), SIGUSR1);//remove
		sleep(1);
	}
}