/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 15:41:45 by frthierr          #+#    #+#             */
/*   Updated: 2020/09/13 16:07:09 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int main(int argc, char const *argv[])
{
	long int	start_time = 0;
	long int	time_now = 0;
	long int	last_print = 0;

	printf("TEST START\n");
	start_time = get_time_now(&start_time);
	while ((time_now = get_time_now(&start_time)) < 1000)
	{
		ft_usleep(100);
		if (time_now != last_print)
			printf("[%ld]\n", time_now);
		last_print = time_now;
	}
	printf("time_end: %ld\n", time_now);
	return 0;
}