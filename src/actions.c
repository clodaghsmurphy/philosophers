/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:06:11 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/23 15:01:04 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	prompt(t_philo *philo, int philo_no, char *str)
{
	long int	time;

	time = print_time() - philo->start_time;
	pthread_mutex_lock(philo->write);
	printf("%ld %d %s", time, philo_no, str);
	pthread_mutex_unlock(philo->write);
}

void	thinking(t_philo *philo, int philo_no)
{
	if (philo->status == 't')
	{
		prompt(philo, philo_no, "is thinking\n");
		philo->status = 'e';
		take_fork(philo, philo_no);
	}
}

void	ft_sleep(t_philo *philo, int philo_no)
{
	if (philo->status == 's')
	{
		prompt(philo, philo_no, "is sleeping\n");
		my_usleep(philo->time_to_sleep);
		philo->status = 't';
	}
}

void	take_fork(t_philo *philo, int philo_no)
{
	int				left;	
	int				right;

	philo->meal_time = malloc(sizeof(pthread_mutex_t));
	if (!philo->meal_time)
		return ;
	pthread_mutex_init(philo->meal_time, NULL);
	left = philo_no;
	right = (philo_no + 1) % philo->no_of_philos;
	pthread_mutex_lock(&philo->fork[left]);
	prompt(philo, philo_no, "has taken a fork\n");
	pthread_mutex_lock(&philo->fork[right]);
	prompt(philo, philo_no, "is eating\n");
	pthread_mutex_lock(philo->meal_time);
	update_meal_time(philo);
	pthread_mutex_unlock(philo->meal_time);
	my_usleep(philo->time_to_eat);
	pthread_mutex_unlock(&philo->fork[left]);
	pthread_mutex_unlock(&philo->fork[right]);
	philo->status = 's';
	ft_sleep(philo, philo_no);
	thinking(philo, philo_no);
}
