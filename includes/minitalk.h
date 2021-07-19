/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 09:53:16 by rponsonn          #+#    #+#             */
/*   Updated: 2021/07/19 17:28:13 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <signal.h>
# define BUFFSIZE 500
//do not let buffsize go below 5
typedef struct s_array
{
	pid_t	pid;
	int		count;
	int		bit;
	char	buff[BUFFER_SIZE];
}	t_array;

void	ft_bit_check(unsigned char bit, pid_t s_pid);
void	ft_listen(void);
int		ft_convert_pid_str(void);
void	ft_store_bit(int sig, siginfo_t *si, void *arg);
void	ft_init(void);
int		ft_add_bit(int sigval);
int		ft_check_null(void);
void	ft_handler(int sig, siginfo_t *si, void *arg);
void	ft_bit_check(unsigned char bit, pid_t s_pid);

#endif
