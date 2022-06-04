/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmyrl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:38:04 by dmyrl             #+#    #+#             */
/*   Updated: 2022/01/29 19:38:07 by dmyrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_philo(t_philo **philo, t_data *info)
{
	size_t	i;

	i = 0;
	*philo = malloc(sizeof(t_philo) * info->phil_num);
	if (!*philo)
		return (1);
	memset(*philo, 0, sizeof(t_philo) * info->phil_num);
	while (i < info->phil_num)
	{
		(*philo)[i].info = info;
		(*philo)[i].phil_id = i + 1;
		(*philo)[i].l_fork = i;
		if (i != info->phil_num - 1)
			(*philo)[i].r_fork = i + 1;
		(*philo)[i].time_last_meal = info->start_time;
		if (pthread_mutex_init(&(*philo)[i].last_meal, NULL))
			return (1);
		if (pthread_mutex_init(&(*philo)[i].full, NULL))
			return (1);
		i++;
	}
	return (0);
}

int	ft_init_mutex(t_data *info)
{
	size_t	i;

	i = -1;
	info->fork = malloc(sizeof(pthread_mutex_t) * info->phil_num);
	if (!info->fork)
		return (1);
	while (++i < info->phil_num)
		if (pthread_mutex_init(&info->fork[i], NULL))
			return (1);
	if (pthread_mutex_init(&info->dead, NULL))
		return (1);
	if (pthread_mutex_init(&info->output, NULL))
		return (1);
	if (pthread_mutex_init(&info->all_full, NULL))
		return (1);
	return (0);
}

int	ft_init_data(int argc, char **argv, t_data *info)
{
	info->phil_num = ft_atoi(argv[1]);
	info->tt_die = ft_atoi(argv[2]);
	info->tt_eat = ft_atoi(argv[3]);
	info->tt_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		info->must_eat = ft_atoi(argv[5]);
		if (!info->must_eat)
			return (1);
	}
	else
		info->must_eat = -1;
	if (!info->phil_num || !info->tt_die || !info->tt_eat || \
	!info->tt_sleep)
		return (1);
	info->start_time = ft_gettime();
	return (0);
}

int	ft_init_threads(t_philo *philo, t_data *info)
{
	size_t	i;

	i = -1;
	while (++i < info->phil_num)
	{
		if (pthread_create(&(philo[i].thread_id), NULL, ft_life, philo + i))
		{
			ft_free(&philo, info);
			return (1);
		}
	}
	return (0);
}
