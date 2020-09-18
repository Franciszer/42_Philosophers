/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_philo_processes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 15:37:10 by frthierr          #+#    #+#             */
/*   Updated: 2020/09/18 11:35:25 by frthierr         ###   ########.fr       */
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

void		*check_eat_routine(void *arg)
{
	t_philo_state	*philo_state;
	long int		index;

	index = 0;
	philo_state = arg;
	if (philo_state->max_eat_count != NOT_SET)
	{
		index = 0;
		while (index < philo_state->max_eat_count)
		{
			sem_wait(philo_state->everybody_ate);
			index++;
		}
		sem_post(philo_state->someone_dead);
	}
	return (NULL);
}

void		delete_processes(t_philo_state *philo_state)
{
	long int	index;
	pthread_t	check_eat;

	pthread_create(&check_eat, NULL, &check_eat_routine, philo_state);
	pthread_detach(check_eat);
	sem_wait(philo_state->someone_dead);
	philo_state->dead = 1;
	index = 0;
	while (index < philo_state->n_philosophers)
		kill(philo_state->philos[index++].liv_pid, SIGKILL);
}
