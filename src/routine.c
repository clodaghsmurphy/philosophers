/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:37:33 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/25 11:40:52 by clmurphy         ###   ########.fr       */
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
		eat_sleep_think(philo, philo->philo_no);
	}
	return (NULL);
}

void	*monitor(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		printf("total meals %d and philo meals %d\n",philo->params->total_meals, philo->nb_meals);
		if ((print_time() - philo->last_meal) > philo->params->time_to_die)
		{
			printf("dead because time since last meal : %ld\n", \
			(print_time() - philo->last_meal));
			philo->params->all_alive = -1;
			end_threads(philo);
			return (NULL);
		}
		if (philo->params->total_meals >= philo->params->no_times_to_eat)
		{
			printf("dead because ate all the meals necessary : %d\n", \
			philo->params->total_meals);
			philo->params->all_alive = -1;
			end_threads(philo);
			return (NULL);
		}
	}
	return (NULL);
}
