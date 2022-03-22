/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:06:11 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/22 15:17:14 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	prompt(t_philo *philo, int philo_no, char *str)
{
	long int	time;

	time = print_time() - philo->start_time;
	pthread_mutex_lock(philo->write);
	printf("%ld Philopher[%d] %s\n", time, philo_no, str);
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
	int	left;
	int	right;

	left = philo_no;
	right = (philo_no + 1) % philo->no_of_philos;
	if (philo->status == 'e')
	{
		pthread_mutex_lock(&philo->fork[left]);
		prompt(philo, philo_no, "takes fork\n");
		pthread_mutex_lock(&philo->fork[right]);
		philo->status = 'e';
		prompt(philo, philo_no, "is eating\n");
		update_meal_time(philo);
		my_usleep(philo->time_to_eat);
		pthread_mutex_unlock(&philo->fork[left]);
		pthread_mutex_unlock(&philo->fork[right]);
		philo->status = 's';
		ft_sleep(philo, philo_no);
	}
}
