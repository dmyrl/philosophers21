/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmyrl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 23:25:51 by dmyrl             #+#    #+#             */
/*   Updated: 2022/01/29 23:25:53 by dmyrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_fork_philo(t_info *info, int *pid)
{
	size_t	i;

	i = 0;
	while (i < info->philo_num)
	{
		pid[i] = fork();
		if (pid[i] < 0)
		{
			while (i > 0)
			{
				kill(pid[i], SIGKILL);
				i--;
			}
			exit(1);
		}
		if (pid[i] == 0)
			ft_life(info, i);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 5 && argc != 6)
		return (ft_error("Error: Wrong number of arguments\n"));
	memset(&info, 0, sizeof(t_info));
	if (ft_init_info(argc, argv, &info))
		return (ft_error("Error: init info\n"));
	ft_destroy_sem(&info);
	if (ft_init_sem(&info))
		return (ft_error("Error: init sem\n"));
	ft_init_philo(&info);
	ft_destroy_sem(&info);
	return (0);
}
