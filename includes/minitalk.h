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

#define BASE10 "0123456789"
#define BASE2 "01"

char	*ft_conv_bin(char *src);
int		ft_atoi_base(char *str, char *base);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	*ft_convert_val_to_str(char val);
void	ft_conv_free(char *ptr1, char *ptr2, char *ptr3);

#endif
