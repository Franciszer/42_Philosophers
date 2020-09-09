/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 12:56:55 by user42            #+#    #+#             */
/*   Updated: 2020/09/09 18:52:13 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H

# define PHILO_ONE_H

# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef char	t_bool;

typedef struct 	s_philo
{
	long int		last_eat;
	int				index;
	struct s_philo	*next;
}				t_philo;

typedef struct  s_philo_state
{
    long int        n_philosophers;
    long int        time_to_die;
    long int        time_to_eat;
    long int        time_to_sleep;
    long int        max_eat_count;
    long int        start_time;
	t_philo			*philos;
}               t_philo_state;



typedef struct timeval t_timeval;

/*
**	ERROR HANDLING
*/

# define ERR_RET(str)	!ft_perror(str) ? 1 : 1

# define ERR_ALLOC	"data allocation failed"
# define ERR_NB_ARGS "invalid arguments\nUsage:\n\
./philo_one number_of_philosopher time_to_die time_to_eat time_to_sleep\
 [number_of_time_each_philosophers_must_eat]\n"
# define ERR_GET_TIME "could not get the program start time"
# define ERR_NEGATIVE_ARG "all arguments must be positive integers"

/*
** LIB FUNCTIONS
*/

size_t			ft_strlen(const char *str);
void			ft_putnbr_fd(int n, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr(char *s);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
long			ft_atol(const char *str);
int				ft_perror(char *msg);


/*
** INITIALIZING DATA
*/

t_bool           get_philo_data(int argc, char const *argv[], t_philo_state *philo_data);
long int	    get_time_now(void);
t_bool			create_philosophers(t_philo_state *philo_state);

/*
** DEFINED VALUES
** 
*/

# define NOT_SET -1

#endif