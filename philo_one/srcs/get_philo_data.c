/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_philo_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 14:01:19 by user42            #+#    #+#             */
/*   Updated: 2020/09/10 17:23:12 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_bool		get_philo_data(int argc, char const *argv[], t_philo_state *philo_data)
{
	t_timeval	timeval;
	
	if (argc < 5 || argc > 6)
		return (ft_perror(ERR_NB_ARGS));
	philo_data->dead = 0;
	if ((philo_data->n_philosophers = ft_atol(argv[1])) < 1||\
	(philo_data->time_to_die = ft_atol(argv[2])) < 0||\
	(philo_data->time_to_eat = ft_atol(argv[3])) < 0||\
	(philo_data->time_to_sleep = ft_atol(argv[4])) < 0||\
	(argv[5] && (philo_data->max_eat_count = ft_atol(argv[5])) < 0 &&\
	philo_data->max_eat_count != NOT_SET))
		return (ft_perror(ERR_NEGATIVE_ARG));
 	if (gettimeofday(&timeval, NULL) != 0)
		return (ft_perror(ERR_GET_TIME));
	philo_data->start_time = timeval.tv_sec * 1000 + timeval.tv_usec / 1000;
	return (1);
}

long int	get_time_now(long int *start_time)
{
	t_timeval		timeval;

	if (gettimeofday(&timeval, NULL) != 0)
			return (ft_perror(ERR_GET_TIME));
	return ((timeval.tv_sec * 1000 + timeval.tv_usec / 1000) - *start_time);
}
