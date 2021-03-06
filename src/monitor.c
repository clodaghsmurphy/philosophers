/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 09:11:01 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/31 21:41:08 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philos(t_philo *philo)
{
	long int	last_meal;
	
	pthread_mutex_lock(philo->lock_meal_time);
	last_meal =  philo->last_meal;
	pthread_mutex_unlock(philo->lock_meal_time);
	if ((print_time() - last_meal) > philo->params->time_to_die)
	{
		prompt(philo, philo->philo_no, "died\n");
		pthread_mutex_lock(philo->params->end);
		philo->params->all_alive = -1;
		pthread_mutex_unlock(philo->params->end);
		return (-1);
	}
	pthread_mutex_lock(philo->params->update_meals);
	if (check_meals(philo, philo->params->total_meals, \
	philo->params->no_times_to_eat) == -1)
		return (-1);
	my_usleep(5);
	return (1);
}

int	check_meals(t_philo *philo, int total_meals, int ntte)
{
	if (total_meals == philo->params->no_of_philos && ntte != -1)
	{
		my_usleep(5);
		pthread_mutex_unlock(philo->params->update_meals);
		pthread_mutex_lock(philo->params->end);
		philo->params->all_alive = -1;
		pthread_mutex_unlock(philo->params->end);
		return (-1);
	}
	else
	{
		pthread_mutex_unlock(philo->params->update_meals);
		return (1);
	}
}

void	*monitor(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (check_philos(philo) == -1)
		{
			return (NULL);
		}
	}
	return (NULL);
}
