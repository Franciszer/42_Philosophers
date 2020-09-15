/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mutexes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 12:29:04 by frthierr          #+#    #+#             */
/*   Updated: 2020/09/15 12:33:17 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	mutex_handler_init(pthread_mutex_t *first, pthread_mutex_t	*second,\
											 t_mutex_handler *mutex_handler)
{
	mutex_handler->first = first;
	mutex_handler->second = second;
	mutex_handler->first_state = 0;
	mutex_handler->second_state = 0;
}

void	mutex_handler_lock(t_mutex_handler *mutex_handler)
{
	
}
