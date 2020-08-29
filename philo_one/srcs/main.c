/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 13:05:07 by user42            #+#    #+#             */
/*   Updated: 2020/08/29 14:05:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int main(int argc, char const *argv[])
{
    t_philo philo_data;

    if (!get_philo_data(argc, argv, &philo_data))
        return (1);
    for (int i = 0; i < argc ; i++)
        ft_printf("%s\n", argv[i]);
    return 0;
}
