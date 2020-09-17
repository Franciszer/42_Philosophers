/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 12:56:55 by user42            #+#    #+#             */
/*   Updated: 2020/09/17 18:33:21 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H

# define PHILO_ONE_H

# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

# define T_TAKEN_FORK 1
# define T_EATING 2
# define T_SLEEPING 3
# define T_THINKING 4
# define T_DEAD 5

/*
** STRUCTURE DEFINITIONS
*/

typedef char	t_bool;

typedef struct	s_philo
{
	long int		last_eat;
	long int		meal_counter;
	pthread_t		liv_tid;
	pthread_t		mon_tid;
	pthread_mutex_t	lock;
	struct s_philo	*next;
}				t_philo;

typedef struct	s_philo_state
{
	long int		n_philosophers;
	long int		time_to_die;
	long int		time_to_eat;
	long int		time_to_sleep;
	long int		max_eat_count;
	long int		start_time;
	long int		who_ate;
	t_bool			dead;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}				t_philo_state;

typedef struct	s_philo_arg
{
	t_philo_state	*philo_state;
	long int		index;
}				t_philo_arg;

typedef	struct	s_mutex_handler
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;
	t_bool			first_state;
	t_bool			second_state;
}				t_mutex_handler;

typedef struct timeval	t_timeval;

/*
**	ERROR HANDLING
*/

# define ERR_ALLOC	"data allocation failed"
# define ERR_NB_ARGS "invalid arguments"
# define ERR_GET_TIME "could not get the program start time"
# define ERR_NEGATIVE_ARG "all arguments must be strictly positive integers"
# define ERR_THREADS "could not do thread processing"
# define ERR_END_THREADS "could not close threads"
# define ERR_ONE_PHILO "there needs to be atleast 2 philosophers"

t_bool			create_philosophers_return(t_philo_state *philo_state);

/*
** LIB FUNCTIONS
*/

int				ft_exit_error(int exit_status, char *msg);
size_t			ft_strlen(const char *str);
void			ft_putnbr_fd(long n, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr(char *s);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
long			ft_atol(const char *str);
int				ft_perror(char *msg);
void			ft_usleep(long int time_in_ms);

/*
** INITIALIZING DATA
*/

t_bool			get_philo_state\
				(int argc, char const *argv[], t_philo_state *philo_data);
t_bool			create_philosophers(t_philo_state *philo_state);
t_bool			init_philo_threads(t_philo_state *philo_state);

/*
** PHILO HANDLING
*/

void			write_philo_action(long int timestamp, long int philo_index,\
														char action_type);
void			write_liv_philo_action\
				(long int timestamp, long int philo_index,\
				char action_type, t_philo_state *philo_state);
long int		get_time_now(long int *start_time);
void			*philo_living_routine(void *philo_arg);
void			*philo_monitoring_routine(void *philo_arg);
void			philo_meal_prep(t_philo_state *philo_state, long int index);
void			register_meal(t_philo_state *philo_state, long int index);
void			end_philo(t_philo_state *philo_state);

/*
** DEFINED VALUES
*/

# define NOT_SET -1

#endif
