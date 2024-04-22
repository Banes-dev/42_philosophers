/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:23:01 by ehay              #+#    #+#             */
/*   Updated: 2024/04/22 15:42:45 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "stdio.h"           // printf and other
# include "unistd.h"          // write
# include "stdlib.h"          // malloc & free
# include "stdarg.h"          // fonction va_
# include "stddef.h"          // size_t
# include "limits.h"          // INT_MIN et INT_MAX
# include "fcntl.h" 		  // Read
# include "string.h" 		  // fonction string
# include "pthread.h"         // thread
# include "sys/time.h"        // time function

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}					t_program;

// Init
void	init_program(t_program *program, t_philo *philos);
void	init_forks(pthread_mutex_t *forks, int philo_num);
void	init_philos(t_philo *philos, t_program *program, pthread_mutex_t *forks,
			char **argv);

// Thread
void	create_thread(t_program *program, t_philo *philos,
			pthread_mutex_t *forks);
int		dead_loop(t_philo *philo);

// Action of philo
void	eat(t_philo philos);
void	sleep_philo(t_philo philos);
void	think(t_philo philos);

// Monitor
void	print_message(char *str, t_philo *philo, int id);
void	*monitor(void *pointer);

// Error
void	ft_error(int num_error);

// Utils
void	destory_all(char *str, t_program *program, pthread_mutex_t *forks);
int		ft_atoi(const char *nptr);
int		ft_usleep(size_t milliseconds);
size_t	get_current_time(void);

#endif