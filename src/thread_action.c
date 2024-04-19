/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:01:44 by ehay              #+#    #+#             */
/*   Updated: 2024/04/19 15:46:21 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// eat
void    eat(t_philo philos)
{
    // gerer fork etc, puis changer last save manger du philo
    print_message("is eating", &philos, philos.id);
    ft_usleep(philos.time_to_eat);
}

// sleep
void    sleep(t_philo philos)
{
    print_message("is sleeping", &philos, philos.id);
    ft_usleep(philos.time_to_sleep);
}

// think
void    think(t_philo philos)
{
    print_message("is thinking", &philos, philos.id);
}