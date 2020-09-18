/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 14:40:31 by user42            #+#    #+#             */
/*   Updated: 2020/09/18 12:07:25 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

long	ft_atol(const char *str)
{
	long long int	number;
	long long int	negative;

	negative = 1;
	number = 0;
	if (!str)
		return (-1);
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		if (*str >= '0' && *str <= '9')
		{
			number = number * 10 + (*str - '0');
			str++;
		}
		else
			return (-1);
	}
	return (number * negative);
}
