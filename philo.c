/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:22:42 by ehay              #+#    #+#             */
/*   Updated: 2024/04/17 15:16:20 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_check_args(char **argv)
{
	// nb philo
	if (argv[1] > 200 && argv[1] < 0)
		ft_error(10);
	// time to
	if (argv[2] < 60 && argv[3] < 60 && argv[4] < 60)
		ft_error(11);
}

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 4)
	{
		ft_check_args(argv);
	}
	else
		ft_error(1);
	return (0);
}
