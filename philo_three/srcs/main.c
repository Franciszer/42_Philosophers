/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 13:05:07 by user42            #+#    #+#             */
/*   Updated: 2020/09/16 15:52:49 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int	main(int argc, char const *argv[])
{
	t_philo_state	philo_state;

	if (!get_philo_state(argc, argv, &philo_state))
		return (1);
	if (!create_philosophers(&philo_state))
		return (ft_exit_error(1, ERR_ALLOC));
	if (!init_philo_threads(&philo_state))
		return (ft_exit_error(1, ERR_THREADS));
	end_philo(&philo_state);
	return (0);
}
