/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:56:23 by ehay              #+#    #+#             */
/*   Updated: 2024/04/25 16:29:07 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_loop(t_philo *philo)
{
	if (philo->num_times_to_eat != -1)
	{
		if (philo->meals_eaten >= philo->num_times_to_eat)
			return (1);
	}
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	*philo_action(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	while (!dead_loop(philo))
	{
		eat(philo);
		sleep_philo(philo);
		think(philo);
	}
	return (pointer);
}

void	create_thread(t_program *program, pthread_mutex_t *forks)
{
	pthread_t	monitor_thread;
	int			i;

	i = 0;
	if (pthread_create(&monitor_thread, NULL, &monitor, program->philos) != 0)
		destory_all("Creation of thread Error", program, forks);
	while (i < program->philos[0].num_of_philos)
	{
		if (pthread_create(&program->philos[i].thread, NULL, &philo_action,
				&program->philos[i]) != 0)
			destory_all("Creation of thread Error", program, forks);
		i++;
	}
	if (pthread_join(monitor_thread, NULL) != 0)
		destory_all("Join of thread join", program, forks);
	i = 0;
	while (i < program->philos[0].num_of_philos)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			destory_all("Join of thread join", program, forks);
		i++;
	}
}
