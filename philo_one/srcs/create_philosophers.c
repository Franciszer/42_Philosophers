/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosophers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 18:23:16 by frthierr          #+#    #+#             */
/*   Updated: 2020/09/13 17:26:58 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_bool	create_philosophers(t_philo_state *philo_state)
{
	long	i;

	if (!(philo_state->philos =\
	(t_philo*)malloc(sizeof(t_philo) * philo_state->n_philosophers)))
		return (0);
	i = -1;
	pthread_mutex_init(&philo_state->write_lock, NULL);
	while (++i < philo_state->n_philosophers)
	{
		philo_state->philos[i].meal_counter = 0;
		if (pthread_mutex_init(&philo_state->philos[i].lock, NULL))
			return (create_philosophers_return(philo_state));
		philo_state->philos[i].last_eat = 0;
		if (i < philo_state->n_philosophers - 1)
			philo_state->philos[i].next = &philo_state->philos[i + 1];
	}
	philo_state->philos[--i].next = &philo_state->philos[0];
	return (1);
}

t_bool	create_philosophers_return(t_philo_state *philo_state)
{
	free(philo_state);
	return (0);
}

t_bool	init_philo_threads(t_philo_state *philo_state)
{
	long int	i;
	t_philo_arg	*philo_liv_arg;
	t_philo_arg	*philo_monitoring_arg;

	i = 0;
	while (i < philo_state->n_philosophers)
	{
		if (!(philo_liv_arg = (t_philo_arg*)malloc(sizeof(t_philo_arg))))
			return (0);
		if (!(philo_monitoring_arg = (t_philo_arg*)malloc(sizeof(t_philo_arg))))
			return (0);
		philo_liv_arg->philo_state = philo_state;
		philo_liv_arg->index = i;
		philo_monitoring_arg->philo_state = philo_state;
		philo_monitoring_arg->index = i;
		pthread_create(&philo_state->philos[i].tid, NULL, &philo_living_routine, philo_liv_arg);
		pthread_create(&philo_state->philos[i].tid, NULL, &philo_monitoring_routine, philo_monitoring_arg);
		i++;
	}
	return (1);
}
