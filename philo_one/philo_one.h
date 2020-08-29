/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 12:56:55 by user42            #+#    #+#             */
/*   Updated: 2020/08/29 14:07:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H

# define PHILO_ONE_H

# include "libft.h"

typedef struct  s_philo
{
    unsigned int    n_philosophers;
    unsigned int    time_to_die;
    unsigned int    time_to_eat;
    unsigned int    time_to_sleep;
    unsigned int    max_eat_count;
}               t_philo;

/*
** PARSING 
*/

char            get_philo_data(int argc, char const *argv[], t_philo *philo_data);

/*
** ERROR MESSAGES
*/

# define ERR_NB_ARGS "invalid arguments\nUsage:\n\
./philo_one number_of_philosopher time_to_die time_to_eat time_to_sleep\
 [number_of_time_each_philosophers_must_eat]"

#endif