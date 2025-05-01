/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luminous <luminous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 03:27:28 by luminous          #+#    #+#             */
/*   Updated: 2025/04/23 09:17:12 by luminous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>
# include <stdbool.h>

typedef enum e_status
{
	DIED,
	EATING,
	SLEEPING,
	THINKING,
	GOT_FORK_1,
	GOT_FORK_2
}	t_status;

typedef enum s_defs
{
	MAX_PHILOS = 250,
	MACRO      = 3
}	t_defs;

typedef struct	s_philo
{
	pthread_t		thread;
	int				id;
	int				meals_eaten;
	int				last_meal;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	left_fork;
}	t_philo;

typedef struct	s_data
{
	int				philos_nb;
	int				time_to_sleep;
	int				time_to_die;
	int				time_to_eat;
	int				limit_of_meal;
	int				is_dead;
	int				start;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}	t_data;

int		ft_atoi(char *str);
bool	is_valid(int argc, char **argv);
int		ft_error(char *str, int status);
long	get_current_time(void);

#endif
