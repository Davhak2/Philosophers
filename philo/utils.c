/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luminous <luminous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 03:45:06 by luminous          #+#    #+#             */
/*   Updated: 2025/04/23 06:28:14 by luminous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return	(ft_error("gettimeofday() error", 0));
	return ((time.tv_usec / 1000) + (time.tv_sec * 1000));
}

static bool	atoi_helper(char *str)
{
	if (*str != '-' && *str != '+')
		return (false);
	if (*str == 48 && *(str + 1))
		return (false);
	if ((*str == '+' || *str == '-') && *(str + 1) == 48 && \
		*(str + 2))
		return (false);
	return (true);
}

int	ft_atoi(char *str)
{
	int		flag;
	long	res;

	flag = 1;
	res = 0;
	if (!atoi_helper(str))
		return (-1);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			return (-1);
		str++;
		if (!*str)
			return (-1);
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		if (res * flag > INT_MAX || res * flag < INT_MIN)
			return (-1);
		str++;
	}
	if (*str)
		return (-1);
	return (res * flag);
}

int	ft_error(char *str, int status)
{
	printf("%s", str);
	return (status);
}

bool	is_valid(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 5 || argc > 6)
		return (ft_error("In your function must be 4 or 5 parameters\n", \
			 false));
	while (argv[++i])
	{
		if (ft_atoi(argv[i]) == -1)
			return (ft_error("Invalid parameters\n", false));
	}
	return (true);
}
