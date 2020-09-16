/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_philo_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 14:01:19 by user42            #+#    #+#             */
/*   Updated: 2020/09/16 15:00:15 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

t_bool		get_philo_state(int argc, char const *argv[],\
							t_philo_state *philo_state)
{
	if (argc < 5 || argc > 6)
		return (ft_perror(ERR_NB_ARGS));
	philo_state->dead = 0;
	if ((philo_state->n_philosophers = ft_atol(argv[1])) < 1 ||\
	(philo_state->time_to_die = ft_atol(argv[2])) < 0 ||\
	(philo_state->time_to_eat = ft_atol(argv[3])) < 0 ||\
	(philo_state->time_to_sleep = ft_atol(argv[4])) < 0 ||\
	(argv[5] && (philo_state->max_eat_count = ft_atol(argv[5])) < 0 &&\
	philo_state->max_eat_count != NOT_SET))
		return (ft_perror(ERR_NEGATIVE_ARG));
	if (philo_state->n_philosophers == 1)
		return (ft_perror(ERR_ONE_PHILO));
	sem_unlink(SEM_FORKS);
	philo_state->forks =\
	sem_open(SEM_FORKS, O_CREAT, 755, (unsigned int)philo_state->n_philosophers);
	sem_unlink(SEM_WRITE);
	philo_state->write_lock =\
	sem_open(SEM_WRITE, O_CREAT, 755, 1);
	philo_state->who_ate = 0;
	return (1);
}

long int	get_time_now(long int *start_time)
{
	t_timeval		timeval;

	if (gettimeofday(&timeval, NULL) != 0)
		return (ft_perror(ERR_GET_TIME));
	return ((timeval.tv_sec * 1000 + timeval.tv_usec / 1000) - *start_time);
}
