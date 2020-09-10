/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:01:42 by frthierr          #+#    #+#             */
/*   Updated: 2020/09/10 16:00:01 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*philo_living_routine(void *philo_arg)
{
	t_philo_state	*philo_state;
	long int		index;

	philo_state = ((t_philo_arg*)philo_arg)->philo_state;
	index = ((t_philo_arg*)philo_arg)->index;
	free(philo_arg);
	while (!g_philo_dead)
	{
		pthread_mutex_lock(&philo_state->philos[index].lock);
		pthread_mutex_lock(&philo_state->philos[index].next->lock);
		WRITE_PHILO_ACTION(T_TAKEN_FORK);
		WRITE_PHILO_ACTION(T_EATING);
		ft_usleep(philo_state->time_to_eat);
		philo_state->philos[index].last_eat = get_time_now(&philo_state->start_time);
		pthread_mutex_unlock(&philo_state->philos[index].next->lock);
		pthread_mutex_unlock(&philo_state->philos[index].lock);
		WRITE_PHILO_ACTION(T_SLEEPING);
		ft_usleep(philo_state->time_to_sleep);
		WRITE_PHILO_ACTION(T_THINKING);
	}
	pthread_mutex_destroy(&philo_state->philos[index].lock);
	pthread_detach(philo_state->philos[index].tid);
	return (NULL);
}

void	*philo_monitoring_routine(void *philo_arg)
{
	t_philo_state	*philo_state;
	long int		index;

	philo_state = ((t_philo_arg*)philo_arg)->philo_state;
	index = ((t_philo_arg*)philo_arg)->index;
	free(philo_arg);
	while (!g_philo_dead)
	{
		if (philo_state->philos[index].last_eat > philo_state->time_to_die)
		{
			write_philo_action(get_time_now(&philo_state->start_time), index, T_DEAD);
			g_philo_dead = 1;
		}
	}
	return (NULL);
}
