/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:01:44 by ehay              #+#    #+#             */
/*   Updated: 2024/04/25 16:48:01 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_mutex_fork(t_philo *philo)
{
	if (philo->id == 0 || philo->id == philo->num_of_philos
		|| philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		print_message("has taken a fork", philo, philo->id);
		pthread_mutex_lock(philo->r_fork);
		print_message("has taken a fork", philo, philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		print_message("has taken a fork", philo, philo->id);
		pthread_mutex_lock(philo->l_fork);
		print_message("has taken a fork", philo, philo->id);
	}
}

// eat
void	eat(t_philo *philo)
{
	if (philo->num_of_philos == 1)
	{
		ft_usleep(philo->time_to_die);
		return ;
	}
	lock_mutex_fork(philo);
	philo->eating = 1;
	print_message("is eating", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten = philo->meals_eaten + 1;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

// sleep
void	sleep_philo(t_philo *philo)
{
	print_message("is sleeping", philo, philo->id);
	ft_usleep(philo->time_to_sleep);
}

// think
void	think(t_philo *philo)
{
	print_message("is thinking", philo, philo->id);
}
