/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:22:42 by ehay              #+#    #+#             */
/*   Updated: 2024/04/18 16:20:37 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args_isdigit(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] < '0' || arg[i] > '9')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_check_args(char **argv)
{
	// nb philo
	if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[1]) <= 0
		|| check_args_isdigit(argv[1]) == 1)
		ft_error(11);
	// time to die
	if (ft_atoi(argv[2]) < 60 || check_args_isdigit(argv[2]) == 1)
		ft_error(12);
	// time to eat
	if (ft_atoi(argv[3]) < 60 || check_args_isdigit(argv[3]) == 1)
		ft_error(13);
	// time to sleep
	if (ft_atoi(argv[4]) < 60 || check_args_isdigit(argv[4]) == 1)
		ft_error(14);
	// optionnal
	if (argv[5] && (ft_atoi(argv[5]) < 0 || check_args_isdigit(argv[5])))
		ft_error(15);
}

int	main(int argc, char **argv)
{
	t_program		program;
	t_philo			philos[200];
	pthread_mutex_t	forks[200];

	if (argc == 5 || argc == 6)
	{
		ft_check_args(argv);
		init_program(&program, philos);
		init_forks(forks, ft_atoi(argv[1]));
		init_philos(philos, &program, forks, argv);
	}
	else
		ft_error(1);
	return (0);
}
