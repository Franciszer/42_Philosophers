/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:01:42 by frthierr          #+#    #+#             */
/*   Updated: 2020/09/15 18:52:14 by frthierr         ###   ########.fr       */
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
	while (!philo_state->dead)
	{
		if (get_time_now(&philo_state->start_time)  - philo_state->philos[index].last_eat >= philo_state->time_to_die)
			write_liv_philo_action(get_time_now(&philo_state->start_time), index + 1, T_DEAD, philo_state);
		pthread_mutex_lock(&philo_state->philos[index].lock);
		WRITE_PHILO_ACTION(T_TAKEN_FORK);
		if (get_time_now(&philo_state->start_time)  - philo_state->philos[index].last_eat >= philo_state->time_to_die)
			write_liv_philo_action(get_time_now(&philo_state->start_time), index + 1, T_DEAD, philo_state);
		pthread_mutex_lock(&philo_state->philos[index].next->lock);
		if (get_time_now(&philo_state->start_time)  - philo_state->philos[index].last_eat >= philo_state->time_to_die)
			write_liv_philo_action(get_time_now(&philo_state->start_time), index + 1, T_DEAD, philo_state);
		WRITE_PHILO_ACTION(T_TAKEN_FORK);
		WRITE_PHILO_ACTION(T_EATING);
		philo_state->philos[index].last_eat = get_time_now(&philo_state->start_time);
		ft_usleep(philo_state->time_to_eat);
		pthread_mutex_unlock(&philo_state->philos[index].lock);
		pthread_mutex_unlock(&philo_state->philos[index].next->lock);
		register_meal(philo_state, index);
		WRITE_PHILO_ACTION(T_SLEEPING);
		ft_usleep(philo_state->time_to_sleep);
		WRITE_PHILO_ACTION(T_THINKING);
	}
	free(philo_arg);
	// printf("/%ld/ liv end\n", index + 1);
	return (NULL);
}

// void	*philo_monitoring_routine(void *philo_arg)
// {
// 	t_philo_state	*philo_state;
// 	long int		index;

// 	philo_state = ((t_philo_arg*)philo_arg)->philo_state;
// 	index = ((t_philo_arg*)philo_arg)->index;
// 	while (!philo_state->philos[index].is_eating && !philo_state->dead)
// 	{
// 		if (get_time_now(&philo_state->start_time)  - philo_state->philos[index].last_eat >= philo_state->time_to_die)
// 		{
// 			write_liv_philo_action(get_time_now(&philo_state->start_time), index + 1, T_DEAD, philo_state);
// 			return (NULL);
// 		}
// 		ft_usleep(100);
// 	}
// 	return (NULL);
// }

void	register_meal(t_philo_state *philo_state, long int index)
{
	if (!philo_state->dead && philo_state->max_eat_count != NOT_SET)
	{
		philo_state->philos[index].meal_counter++;
		if (philo_state->philos[index].meal_counter == philo_state->max_eat_count)
			philo_state->who_ate++;
		if (philo_state->who_ate == philo_state->n_philosophers)
			philo_state->dead = 1;
	}
}
