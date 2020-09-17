/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:01:42 by frthierr          #+#    #+#             */
/*   Updated: 2020/09/17 21:12:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	philo_living_routine(void *philo_arg)
{
	t_philo_state	*philo_state;
	long int		index;

	philo_state = ((t_philo_arg*)philo_arg)->philo_state;
	index = ((t_philo_arg*)philo_arg)->index;
	pthread_create(&philo_state->philos[index].mon_tid, NULL,\
	&philo_monitoring_routine, philo_arg);
	while (!philo_state->dead)
	{
		philo_meal_prep(philo_state, index);
		ft_usleep(philo_state->time_to_eat);
		sem_post(philo_state->forks);
		sem_post(philo_state->forks);
		// register_meal(philo_state, index);
		write_liv_philo_action(get_time_now(&philo_state->start_time),\
											index + 1, T_SLEEPING, philo_state);
		ft_usleep(philo_state->time_to_sleep);
		write_liv_philo_action(get_time_now(&philo_state->start_time),\
											index + 1, T_THINKING, philo_state);
	}
	return ;
}

void	philo_meal_prep(t_philo_state *philo_state, long int index)
{
	sem_wait(philo_state->forks);
	write_liv_philo_action(get_time_now(&philo_state->start_time),\
										index + 1, T_TAKEN_FORK, philo_state);
	sem_wait(philo_state->forks);
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
		if (philo_state->philos[index].ate !=\
		philo_state->max_eat_count)
			++philo_state->philos[index].ate;
		else
		{
			sem_post(philo_state->everybody_ate);
			philo_state->max_eat_count = NOT_SET;
		}
	}
}

void	*philo_monitoring_routine(void *philo_arg)
{
	t_philo_state	*philo_state;
	long int		index;

	philo_state = ((t_philo_arg*)philo_arg)->philo_state;
	index = ((t_philo_arg*)philo_arg)->index;
	free(philo_arg);
	while (!philo_state->dead)
	{
		if (get_time_now(&philo_state->start_time) -\
		philo_state->philos[index].last_eat >= philo_state->time_to_die)
		{
			write_liv_philo_action(get_time_now(&philo_state->start_time),\
				index + 1, T_DEAD, philo_state);
			sem_post(philo_state->someone_dead);
		}
		ft_usleep(5);
	}
	return (NULL);
}
