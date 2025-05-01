/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luminous <luminous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 06:05:41 by luminous          #+#    #+#             */
/*   Updated: 2025/04/23 09:18:34 by luminous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_data(t_data *data, char **argv)
{
	data->philos_nb = ft_atoi(argv[1]);
	if (data->philos_nb < 1 || data->philos_nb > MAX_PHILOS)
		return (ft_error("Invalid parameters\n", NULL, 1));
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->limit_of_meal = ft_atoi(argv[5]);
	else
		data->limit_of_meal = -1;
	data->is_dead = 0;
	data->start = get_current_time();
	return (0);
}

static int	allocate(t_data *data)
{
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->philos_nb);
	if (!data->forks)
		return (ft_error("Allocation failed", data, 1));
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->philos_nb);
	if (!data->philos)
	{
	}
}
