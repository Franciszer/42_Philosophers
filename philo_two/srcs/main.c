/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 13:05:07 by user42            #+#    #+#             */
/*   Updated: 2020/09/09 18:53:25 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int main(int argc, char const *argv[])
{
    t_philo_state philo_state;

    if (!get_philo_data(argc, argv, &philo_state))
        return (1);
    if (!create_philosophers(&philo_state))
		return (ERR_RET(ERR_ALLOC));
	free(philo_state.philos);
    return (0);
}
