/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 15:52:40 by frthierr          #+#    #+#             */
/*   Updated: 2020/09/10 17:57:32 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	end_philo(t_philo_state *philo_state)
{
	long int	i;

	i = 0;
	
	while (i < philo_state->n_philosophers)
	{
		pthread_join(philo_state->philos[i].tid, NULL);
		i++;
	}
	printf("END\n");
	// pthread_mutex_destroy(&philo_state->write_lock);
}
