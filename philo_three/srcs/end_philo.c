/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 15:52:40 by frthierr          #+#    #+#             */
/*   Updated: 2020/09/17 20:58:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	end_philo(t_philo_state *philo_state)
{
	sem_unlink(SEM_DEAD);
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_WRITE);
	sem_close(philo_state->forks);
	sem_close(philo_state->write_lock);
	sem_close(philo_state->someone_dead);
	sem_unlink(SEM_EAT);
	sem_close(philo_state->everybody_ate);
	free(philo_state->philos);
}
