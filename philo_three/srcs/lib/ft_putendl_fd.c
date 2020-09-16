/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:37:20 by frthierr          #+#    #+#             */
/*   Updated: 2020/09/16 15:52:19 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd((char*)s, fd);
	ft_putchar_fd('\n', fd);
}
