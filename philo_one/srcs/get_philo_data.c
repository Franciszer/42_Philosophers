/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_philo_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 14:01:19 by user42            #+#    #+#             */
/*   Updated: 2020/09/09 16:16:01 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

char    get_philo_data(int argc, char const *argv[], t_philo_state *philo_data)
{
	if (argc < 5 || argc > 6)
		return (ft_perror(ERR_NB_ARGS));
	if ((philo_data->n_philosophers = ft_atol(argv[1])) < 0||\
	(philo_data->time_to_die = ft_atol(argv[2])) < 0||\
	(philo_data->time_to_eat = ft_atol(argv[3])) < 0||\
	(philo_data->time_to_sleep = ft_atol(argv[4])) < 0||\
	(argv[5] && (philo_data->max_eat_count = ft_atol(argv[5])) < 0 &&\
	philo_data->max_eat_count != NOT_SET))
		return (ft_perror(ERR_NEGATIVE_ARG));
	else
		philo_data->max_eat_count = 0;
	get_time_now();
	return (1);    
}

long int	get_time_now(void)
{
	static long int	start_time;
	t_timeval		timeval;

	if (!start_time)
	{
		if (gettimeofday(&timeval, NULL) != 0)
			return (ft_perror(ERR_GET_TIME));
		start_time = timeval.tv_sec * 1000 + timeval.tv_usec / 1000;
		return (1);
	}
	else
	{
		if (gettimeofday(&timeval, NULL) != 0)
			return (ft_perror(ERR_GET_TIME));
		return ((timeval.tv_sec * 1000 + timeval.tv_usec / 1000) - start_time);
	}
}