/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:01:42 by frthierr          #+#    #+#             */
/*   Updated: 2020/09/17 14:17:37 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*philo_living_routine(void *philo_arg)
{
	t_philo_state	*philo_state;
	long int		index;

	philo_state = ((t_philo_arg*)philo_arg)->philo_state;
	index = ((t_philo_arg*)philo_arg)->index;
	if (index % 2 == 1)
		ft_usleep(philo_state->time_to_eat / 10);
	pthread_create(&philo_state->philos[index].mon_tid, NULL,\
	&philo_monitoring_routine, philo_arg);
	pthread_detach(philo_state->philos[index].mon_tid);
	while (!philo_state->dead)
	{
		philo_meal_prep(philo_state, index);
		ft_usleep(philo_state->time_to_eat);
		pthread_mutex_unlock(&philo_state->philos[index].lock);
		pthread_mutex_unlock(&philo_state->philos[index].next->lock);
		register_meal(philo_state, index);
		write_liv_philo_action(get_time_now(&philo_state->start_time),\
											index + 1, T_SLEEPING, philo_state);
		ft_usleep(philo_state->time_to_sleep);
		write_liv_philo_action(get_time_now(&philo_state->start_time),\
											index + 1, T_THINKING, philo_state);
	}
	free(philo_arg);
	return (NULL);
}

void	philo_meal_prep(t_philo_state *philo_state, long int index)
{
	pthread_mutex_lock(&philo_state->philos[index].lock);
	write_liv_philo_action(get_time_now(&philo_state->start_time),\
										index + 1, T_TAKEN_FORK, philo_state);
	pthread_mutex_lock(&philo_state->philos[index].next->lock);
	write_liv_philo_action(get_time_now(&philo_state->start_time),\
									index + 1, T_TAKEN_FORK, philo_state);
	write_liv_philo_action(get_time_now(&philo_state->start_time),\
									index + 1, T_EATING, philo_state);
	philo_state->philos[index].last_eat =\
						get_time_now(&philo_state->start_time);
}

void	register_meal(t_philo_state *philo_state, long int index)
{
	if (!philo_state->dead && philo_state->max_eat_count != NOT_SET)
	{
		philo_state->philos[index].meal_counter++;
		if (philo_state->philos[index].meal_counter ==\
			philo_state->max_eat_count)
			philo_state->who_ate++;
		if (philo_state->who_ate == philo_state->n_philosophers)
			philo_state->dead = 1;
	}
}

void	*philo_monitoring_routine(void *philo_arg)
{
	t_philo_state	*philo_state;
	long int		index;

	philo_state = ((t_philo_arg*)philo_arg)->philo_state;
	index = ((t_philo_arg*)philo_arg)->index;
	while (!philo_state->dead)
	{
		if (get_time_now(&philo_state->start_time) -\
		philo_state->philos[index].last_eat >= philo_state->time_to_die)
			write_liv_philo_action(get_time_now(&philo_state->start_time),\
				index + 1, T_DEAD, philo_state);
		ft_usleep(5);
	}
	return (NULL);
}
