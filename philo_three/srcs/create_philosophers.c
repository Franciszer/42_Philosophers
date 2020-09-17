/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosophers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 18:23:16 by frthierr          #+#    #+#             */
/*   Updated: 2020/09/17 20:58:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

t_bool	create_philosophers(t_philo_state *philo_state)
{
	long	i;

	if (!(philo_state->philos =\
	(t_philo*)malloc(sizeof(t_philo) * philo_state->n_philosophers)))
		return (0);
	i = -1;
	while (++i < philo_state->n_philosophers)
	{
		philo_state->philos[i].ate = 0;
		philo_state->philos[i].meal_counter = 0;
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
