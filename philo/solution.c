/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmyrl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:37:40 by dmyrl             #+#    #+#             */
/*   Updated: 2022/01/29 19:37:43 by dmyrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_thinking(t_philo *ph)
{
	ft_printer(ph, "is thinking");
}

void	ft_eating(t_philo *ph, size_t fork_1, size_t fork_2)
{
	pthread_mutex_lock(&ph->info->fork[fork_1]);
	ft_printer(ph, "has taken a fork");
	pthread_mutex_lock(&ph->info->fork[fork_2]);
	ft_printer(ph, "has taken a fork");
	pthread_mutex_lock(&ph->last_meal);
	ph->time_last_meal = ft_gettime();
	pthread_mutex_unlock(&ph->last_meal);
	ft_printer(ph, "is eating");
	ft_usleep(ph->info->tt_eat);
	pthread_mutex_unlock(&ph->info->fork[fork_1]);
	pthread_mutex_unlock(&ph->info->fork[fork_2]);
	ph->nbr_meals++;
	if (ph->nbr_meals >= ph->info->must_eat && ph->info->must_eat)
	{
		pthread_mutex_lock(&ph->full);
		ph->flag_full = 1;
		pthread_mutex_unlock(&ph->full);
	}
}

void	ft_sleeping(t_philo *ph)
{
	ft_printer(ph, "is sleeping");
	ft_usleep(ph->info->tt_sleep);
}

void	*ft_life(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	while (1)
	{
		pthread_mutex_lock(&ph->info->all_full);
		pthread_mutex_lock(&ph->info->dead);
		if (ph->info->flag_dead || ph->info->flag_all_full)
		{
			pthread_mutex_unlock(&ph->info->dead);
			pthread_mutex_unlock(&ph->info->all_full);
			break ;
		}
		pthread_mutex_unlock(&ph->info->dead);
		pthread_mutex_unlock(&ph->info->all_full);
		ft_thinking(ph);
		if (ph->phil_id % 2)
			ft_eating(ph, ph->l_fork, ph->r_fork);
		else
			ft_eating(ph, ph->r_fork, ph->l_fork);
		ft_sleeping(ph);
	}
	return (0);
}
