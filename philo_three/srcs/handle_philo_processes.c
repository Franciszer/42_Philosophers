/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_philo_processes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 15:37:10 by frthierr          #+#    #+#             */
/*   Updated: 2020/09/17 18:16:49 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

t_bool	create_processes(t_philo_state *philo_state)
{
	long int	index;
	t_philo_arg	*philo_arg;
	t_timeval	timeval;

	if (gettimeofday(&timeval, NULL) != 0)
		return (ft_exit_error(1, ERR_GET_TIME));
	philo_state->start_time = timeval.tv_sec * 1000 + timeval.tv_usec / 1000;
	index = 0;
	while (index < philo_state->n_philosophers)
	{
		if (!(philo_state->philos[index++].liv_pid = fork()))
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
	}
	return (0);
}

void	delete_processes(t_philo_state *philo_state)
{
	long int	index;

	sem_wait(philo_state->someone_dead);
	index = 0;
	while (index < philo_state->n_philosophers)
		kill(philo_state->philos[index++].liv_pid, SIGKILL);
}
