/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_philo_action.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 13:32:03 by frthierr          #+#    #+#             */
/*   Updated: 2020/09/10 18:42:54 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	write_philo_action(long int timestamp, long int philo_index,\
							char action_type)
{
	ft_putnbr_fd(timestamp, STDOUT_FILENO);
	write(STDOUT_FILENO, " ", 1);
	ft_putnbr_fd(philo_index, STDOUT_FILENO);
	write(STDOUT_FILENO, " ", 1);
	if (action_type == T_TAKEN_FORK)
		write(STDOUT_FILENO, "has taken a fork", 16);
	else if (action_type == T_EATING)
		write(STDOUT_FILENO, "is eating", 9);
	else if (action_type == T_SLEEPING)
		write(STDOUT_FILENO, "is sleeping", 11);
	else if (action_type == T_THINKING)
		write(STDOUT_FILENO, "is thinking", 11);
	else if (action_type == T_DEAD)
		write(STDOUT_FILENO, "is dead", 7);
	write(STDOUT_FILENO, "\n", 1);
}
void	write_liv_philo_action(long int timestamp, long int philo_index,\
							char action_type, t_philo_state *philo_state)
{
	pthread_mutex_lock(&philo_state->write_lock);
	if (!philo_state->dead)
	{
		write_philo_action(timestamp, philo_index, action_type);
	}
	pthread_mutex_unlock(&philo_state->write_lock);
}
