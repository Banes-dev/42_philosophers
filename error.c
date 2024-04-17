/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:52:15 by ehay              #+#    #+#             */
/*   Updated: 2024/04/17 15:04:46 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(int num_error)
{
	if (num_error == 1)
	{
		printf("\033[96mError : \033[91mnot 4 or 5 args.\033[0m\n");
		printf("\033[96mTry : \033[33m./philo <nb_philo> <time_to_die> <time_to_eat> <time_to_sleep>\033[0m\n");
	}
	if (num_error == 10)
		printf("\033[96mError : \033[91mtime to must be >= 60\033[0m\n");
	exit(1);
}
