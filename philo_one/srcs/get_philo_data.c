/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_philo_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 14:01:19 by user42            #+#    #+#             */
/*   Updated: 2020/08/29 14:05:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

char    get_philo_data(int argc, char const *argv[], t_philo *philo_data)
{
    if (argc < 5 || argc > 6)
        return (ft_perror(ERR_NB_ARGS));
    philo_data->n_philosophers = (unsigned int)ft_atoi(argv[1]);
    philo_data->time_to_die = (unsigned int)ft_atoi(argv[2]);
    philo_data->time_to_eat = (unsigned int)ft_atoi(argv[3]);
    philo_data->time_to_sleep = (unsigned int)ft_atoi(argv[4]);
    if (argv[5])
        philo_data->max_eat_count = (unsigned int)ft_atoi(argv[5]);
    else
        philo_data->max_eat_count = 0;
    return (1);    
}
