/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmyrl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:36:52 by dmyrl             #+#    #+#             */
/*   Updated: 2022/01/29 19:36:56 by dmyrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(char *str)
{
	printf("%s", str);
	return (1);
}

size_t	ft_atoi(const char *str)
{
	int			i;
	size_t		n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		n = n * 10 + str[i] - 48;
		i++;
	}
	return (n);
}

size_t	ft_gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((size_t)tv.tv_sec * 1000 + (size_t)tv.tv_usec / 1000);
}

void	ft_usleep(size_t time)
{
	size_t	res;

	res = ft_gettime() + time;
	while (ft_gettime() < res)
	{
		usleep(50);
	}
}

void	ft_printer(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->info->output);
	pthread_mutex_lock(&philo->info->dead);
	if (philo->info->flag_dead)
	{
		pthread_mutex_unlock(&philo->info->output);
		pthread_mutex_unlock(&philo->info->dead);
		return ;
	}
	pthread_mutex_unlock(&philo->info->dead);
	printf("%zu %zu %s\n", ft_gettime() - philo->info->start_time, \
	philo->phil_id, str);
	pthread_mutex_unlock(&philo->info->output);
}
