/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 09:53:16 by rponsonn          #+#    #+#             */
/*   Updated: 2021/07/12 16:20:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <signal.h>

typedef struct s_array
{
    int count;
    int bit;
    char buff[100];
}              t_array;


void	ft_bit_check(unsigned char bit, pid_t s_pid);
void    ft_listen(void);
int ft_convert_pid_str(void);
int	ft_store_bit(int sig, siginfo_t *si, void *arg);
void	ft_init(void);
int	ft_add_bit(int sigval);
int	ft_check_null(void);
int	ft_write_buffer(void);



#endif
