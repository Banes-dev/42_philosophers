/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:23:01 by ehay              #+#    #+#             */
/*   Updated: 2024/04/17 15:26:32 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO
# define PHILO

# include "stdio.h"           // printf and other
# include "unistd.h"          // write
# include "stdlib.h"          // malloc & free
# include "stdarg.h"          // fonction va_
# include "stddef.h"          // size_t
# include "limits.h"          // INT_MIN et INT_MAX
# include "fcntl.h" 		  // Read
# include "string.h" 		  // fonction string

// Error
void	ft_error(int num_error);

// Utils
int		ft_atoi(const char *nptr);

#endif