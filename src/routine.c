/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:37:33 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/27 19:47:06 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo			*philo;
	t_param			*params;

	philo = (t_philo *)arg;
	params = philo->params;
	if (params->no_of_philos == 1)
	{
		printf("%ld 1 has taken a fork", print_time() - philo->start_time);
		return (NULL);
	}
	pthread_create(philo->waiter, NULL, &monitor, (void *)philo);
	while (1)
	{
		if (!still_alive(params))
		{
			return (NULL);
		}
		eat_sleep_think(philo, philo->philo_no);
	}
	return (NULL);
}

int	still_alive(t_param *params)
{
	pthread_mutex_lock(params->update_meals);
	pthread_mutex_lock(params->end);
	if (params->all_alive == -1 || \
	(params->total_meals >= params->no_times_to_eat \
	&& params->no_times_to_eat != -1))
	{
		pthread_mutex_unlock(params->update_meals);
		pthread_mutex_unlock(params->end);
		return (0);
	}
	pthread_mutex_unlock(params->update_meals);
	pthread_mutex_unlock(params->end);
	return (1);
}

int	check_philos(t_philo *philo)
{
	int	last_meal;

	pthread_mutex_lock(philo->lock_meal);
	last_meal = print_time() - philo->last_meal;
	pthread_mutex_unlock(philo->lock_meal);
	if (last_meal >= philo->params->time_to_die)
	{
		prompt(philo, philo->philo_no, "Dead\n");
		pthread_mutex_lock(philo->params->end);
		philo->params->all_alive = -1;
		pthread_mutex_unlock(philo->params->end);
		return (-1);
	}
	pthread_mutex_lock(philo->params->update_meals);
	if (check_meals(philo, philo->params->total_meals, \
	philo->params->no_times_to_eat) == -1)
		return (-1);
	pthread_mutex_unlock(philo->params->update_meals);
	usleep(100);
	return (1);
}

int	check_meals(t_philo *philo, int total_meals, int ntte)
{
	if (total_meals >= ntte && ntte != -1)
	{
		prompt(philo, philo->philo_no, "Finished eating\n");
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
