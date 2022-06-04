/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmyrl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 23:24:53 by dmyrl             #+#    #+#             */
/*   Updated: 2022/01/29 23:24:57 by dmyrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_init_philo(t_info *info)
{
	size_t	i;
	int		*pid;
	int		pid_killer;

	pid = malloc(sizeof(int) * info->philo_num);
	ft_fork_philo(info, pid);
	pid_killer = fork();
	if (pid_killer == 0)
	{
		sem_wait(info->death);
		i = 0;
		while (i < info->philo_num)
		{
			kill(pid[i], SIGKILL);
			i++;
		}
		exit (0);
	}
	i = 0;
	while (i < info->philo_num)
	{
		waitpid(pid[i], NULL, 0);
		i++;
	}
	free (pid);
}

int	ft_init_info(int argc, char **argv, t_info *info)
{
	info->philo_num = ft_atoi(argv[1]);
	info->tt_die = ft_atoi(argv[2]);
	info->tt_eat = ft_atoi(argv[3]);
	info->tt_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		info->eat_num = ft_atoi(argv[5]);
		if (!info->eat_num)
			return (1);
	}
	else
		info->eat_num = -1;
	if (!info->philo_num || !info->tt_die || !info->tt_eat || \
	!info->tt_sleep)
		return (1);
	info->start_time = ft_get_time();
	return (0);
}

void	ft_destroy_sem(t_info *info)
{
	sem_unlink("output");
	sem_unlink("forks");
	sem_unlink("death");
	sem_close(info->output);
	sem_close(info->forks);
	sem_close(info->death);
}

int	ft_init_sem(t_info *info)
{
	info->output = sem_open("output", O_CREAT | O_EXCL, 0664, 1);
	if (info->output == SEM_FAILED)
	{
		ft_destroy_sem(info);
		return (1);
	}
	info->forks = sem_open("forks", O_CREAT | O_EXCL, 0664, info->philo_num);
	if (info->forks == SEM_FAILED)
	{
		ft_destroy_sem(info);
		return (1);
	}
	info->death = sem_open("death", O_CREAT | O_EXCL, 0664, 0);
	if (info->death == SEM_FAILED)
	{
		ft_destroy_sem(info);
		return (1);
	}
	return (0);
}
