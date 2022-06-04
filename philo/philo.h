/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmyrl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:35:25 by dmyrl             #+#    #+#             */
/*   Updated: 2022/01/29 19:35:26 by dmyrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_data
{
	size_t			phil_num;
	size_t			tt_eat;
	size_t			tt_sleep;
	size_t			tt_die;
	size_t			must_eat;
	int				flag_all_full;
	int				flag_dead;
	size_t			start_time;
	pthread_mutex_t	dead;
	pthread_mutex_t	*fork;
	pthread_mutex_t	output;
	pthread_mutex_t	all_full;
}				t_data;

typedef struct s_philo
{
	size_t			l_fork;
	size_t			r_fork;
	size_t			nbr_meals;
	pthread_t		thread_id;
	size_t			phil_id;
	t_data			*info;
	int				flag_full;
	size_t			time_last_meal;
	pthread_mutex_t	full;
	pthread_mutex_t	last_meal;
}				t_philo;

size_t	ft_atoi(const char *str);
int		ft_error(char *str);
void	*ft_life(void *philo);
size_t	ft_gettime(void);
int		ft_init_philo(t_philo **philo, t_data *info);
int		ft_init_mutex(t_data *info);
int		ft_init_data(int argc, char **argv, t_data *info);
int		ft_init_threads(t_philo *philo, t_data *info);
void	ft_printer(t_philo *philo, char *str);
void	ft_usleep(size_t time);
void	ft_free(t_philo **ph, t_data *info);

#endif
