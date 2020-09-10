/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:27:37 by frthierr          #+#    #+#             */
/*   Updated: 2020/09/10 14:31:47 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_usleep(long int time_in_ms)
{
	long int	time_elapsed;

	time_elapsed = 0;
	while ((time_elapsed = get_time_now(&time_elapsed)) < time_in_ms)
		usleep(time_in_ms);
}
