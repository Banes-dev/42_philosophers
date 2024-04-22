/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:01:44 by ehay              #+#    #+#             */
/*   Updated: 2024/04/22 15:35:44 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// eat
void	eat(t_philo philos)
{
	pthread_mutex_lock(philos.r_fork);
	print_message("has taken a fork", &philos, philos.id);
	if (philos.num_of_philos == 1)
	{
		ft_usleep(philos.time_to_die);
		pthread_mutex_unlock(philos.r_fork);
		return ;
	}
	pthread_mutex_lock(philos.l_fork);
	print_message("has taken a fork", &philos, philos.id);
	philos.eating = 1;
	print_message("is eating", &philos, philos.id);
	pthread_mutex_lock(philos.meal_lock);
	philos.last_meal = get_current_time();
	philos.meals_eaten = philos.meals_eaten + 1;
	pthread_mutex_unlock(philos.meal_lock);
	ft_usleep(philos.time_to_eat);
	philos.eating = 0;
	pthread_mutex_unlock(philos.r_fork);
	pthread_mutex_unlock(philos.l_fork);
}

// sleep
void	sleep_philo(t_philo philos)
{
	print_message("is sleeping", &philos, philos.id);
	ft_usleep(philos.time_to_sleep);
}

// think
void	think(t_philo philos)
{
	print_message("is thinking", &philos, philos.id);
}
