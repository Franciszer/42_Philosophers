/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_philo_processes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 15:37:10 by frthierr          #+#    #+#             */
/*   Updated: 2020/09/17 18:55:30 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	init_time(t_philo_state *philo_state)
{
	t_timeval	timeval;

	gettimeofday(&timeval, NULL);
	philo_state->start_time = timeval.tv_sec * 1000 + timeval.tv_usec / 1000;
}

t_bool		create_processes(t_philo_state *philo_state)
{
	long int	index;
	pid_t		tmp;
	t_philo_arg	*philo_arg;

	index = 0;
	tmp = 0;
	init_time(philo_state);
	while ((!index || tmp) && index < philo_state->n_philosophers)
	{
		if (!(tmp = fork()))
		{
			if (!(philo_arg = (t_philo_arg*)malloc(sizeof(t_philo_arg))))
				return (1);
			philo_arg->index = index;
			philo_arg->philo_state = philo_state;
			philo_state->philos[index].last_eat =\
				get_time_now(&philo_state->start_time);
			philo_living_routine(philo_arg);
			exit(0);
		}
		else
			philo_state->philos[index++].liv_pid = tmp;
	}
	return (0);
}

void		delete_processes(t_philo_state *philo_state)
{
	long int	index;

	sem_wait(philo_state->someone_dead);
	index = 0;
	while (index < philo_state->n_philosophers)
		kill(philo_state->philos[index++].liv_pid, SIGKILL);
}
