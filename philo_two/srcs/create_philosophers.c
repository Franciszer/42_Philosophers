/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosophers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 18:23:16 by frthierr          #+#    #+#             */
/*   Updated: 2020/09/09 18:45:14 by frthierr         ###   ########.fr       */
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
	while (++i < philo_state->n_philosophers)
	{
		philo_state->philos[i].index = i + 1;
		philo_state->philos[i].last_eat = 0;
		if (i < philo_state->n_philosophers - 1)
			philo_state->philos[i].next = &philo_state->philos[i + 1];
	}
	philo_state->philos[i].next = &philo_state->philos[0];
	return (1);
}
