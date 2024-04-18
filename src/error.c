/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:52:15 by ehay              #+#    #+#             */
/*   Updated: 2024/04/18 16:11:21 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(int num_error)
{
	if (num_error == 1)
	{
		printf("\033[96mError : \033[91mnot 4 or 5 args.\033[0m\n");
		printf("\033[96mTry : \033[33m./philo <nb_philo> <time_to_die> ");
		printf("<time_to_eat> <time_to_sleep>\033[0m\n");
	}
	if (num_error == 11)
		printf("\033[96mError : \033[91minvalid nunber of philo\033[0m\n");
	if (num_error == 12)
		printf("\033[96mError : \033[91minvalid time to die\033[0m\n");
	if (num_error == 13)
		printf("\033[96mError : \033[91minvalid time to eat\033[0m\n");
	if (num_error == 14)
		printf("\033[96mError : \033[91minvalid time to sleep\033[0m\n");
	if (num_error == 15)
		printf("\033[96mError : \033[91minvalid must eat\033[0m\n");
	exit(1);
}
