/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 09:53:16 by rponsonn          #+#    #+#             */
/*   Updated: 2021/07/10 17:51:17 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <signal.h>

void	ft_bit_check(unsigned char bit, pid_t s_pid);
void	ft_listen(void);

#endif
