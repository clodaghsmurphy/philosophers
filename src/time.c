/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 09:07:24 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/29 11:45:06 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_usleep(int time_to)
{
	long int	sleep_time;
	long int	tmp;

	tmp = print_time();
	sleep_time = (long int)time_to;
	while ((print_time() - tmp) < sleep_time)
		usleep(sleep_time);
}

long int	print_time(void)
{
	struct timeval	tv;
	long int		time_ms;

	gettimeofday(&tv, NULL);
	time_ms = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return (time_ms);
}

void	update_meal_time(t_philo *philo)
{
	philo->last_meal = print_time();
	pthread_mutex_unlock(philo->lock_meal_time);
	philo->nb_meals++;
	if (philo->nb_meals == philo->params->no_times_to_eat)
		philo->params->total_meals++;
	pthread_mutex_unlock(philo->params->update_meals);
}
