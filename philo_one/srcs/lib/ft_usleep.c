/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:27:37 by frthierr          #+#    #+#             */
/*   Updated: 2020/09/15 16:49:27 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_usleep(long int time_in_ms)
{
	long int	start_time;

	start_time = 0;
	start_time = get_time_now(&start_time);
	while (get_time_now(&start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}
