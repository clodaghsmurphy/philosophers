/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 09:11:01 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/30 16:49:24 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philos(t_philo *philo)
{
	long int	last_meal;
	pthread_mutex_lock(philo->params->update_meals);
	if (check_meals(philo, philo->params->total_meals, \
	philo->params->no_times_to_eat) == -1)
		return (-1);
	pthread_mutex_unlock(philo->params->update_meals);
	pthread_mutex_lock(philo->lock_meal_time);
	last_meal = print_time() - philo->last_meal;
	if (last_meal >= philo->params->time_to_die)
	{
		pthread_mutex_unlock(philo->lock_meal_time);
		prompt(philo, philo->philo_no, "Philosopher died\n");
		pthread_mutex_lock(philo->params->end);
		philo->params->all_alive = -1;
		pthread_mutex_unlock(philo->params->end);
		return (-1);
	}
	pthread_mutex_unlock(philo->lock_meal_time);

	my_usleep(1);
	return (1);
}

int	check_meals(t_philo *philo, int total_meals, int ntte)
{
	//printf("total meals : %d and ntte %d\n", total_meals, ntte);
	if (total_meals == philo->params->no_of_philos && ntte != -1)
	{
		//total_meals == nb of philos
		prompt(philo, philo->philo_no, \
		"All philos have eaten required meals\n");
		pthread_mutex_lock(philo->params->end);
		philo->params->all_alive = -1;
		pthread_mutex_unlock(philo->params->end);
		pthread_mutex_unlock(philo->params->update_meals);
		return (-1);
	}
	else
		return (1);
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
