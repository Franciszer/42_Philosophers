/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 12:56:55 by user42            #+#    #+#             */
/*   Updated: 2020/08/29 15:11:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H

# define PHILO_ONE_H

# include <sys/time.h>
# include "libft.h"

typedef struct  s_philo
{
    long int        n_philosophers;
    long int        time_to_die;
    long int        time_to_eat;
    long int        time_to_sleep;
    long int        max_eat_count;
    long int        start_time;
}               t_philo;

typedef struct timeval t_timeval;

/*
** INITIALIZING DATA
*/

char            get_philo_data(int argc, char const *argv[], t_philo *philo_data);
long int	    get_time_now(void);

/*
** DEFINED VALUES
** 
*/

# define NOT_SET -1

/*
** ERROR MESSAGES
*/

# define ERR_NB_ARGS "invalid arguments\nUsage:\n\
./philo_one number_of_philosopher time_to_die time_to_eat time_to_sleep\
 [number_of_time_each_philosophers_must_eat]"

# define ERR_GET_TIME "could not get the program start time"

# define ERR_NEGATIVE_ARG "all arguments must be positive integers"

#endif