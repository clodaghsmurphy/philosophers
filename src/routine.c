/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:37:33 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/24 13:45:45 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo			*philo;
	t_param			*params;
	int				i;

	i = 0;
	philo = (t_philo *)arg;
	params = philo->params;
	pthread_create(philo->waiter, NULL, &monitor, (void *)philo);
	if (params->no_times_to_eat != -1)
	{
		while (i < params->no_times_to_eat)
		{
			eat_sleep_think(philo, philo->philo_no);
			i++;
		}
	}
	else
	{
		while (1)
		{
			eat_sleep_think(philo, philo->philo_no);
		}
	}
	return (NULL);
}

void	*monitor(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if ((print_time() - philo->last_meal) > philo->params->time_to_die)
		{
			printf("dead because time since last meal : %ld\n", \
			(print_time() - philo->last_meal));
			end_threads(philo);
			exit(0);
			return (NULL);
		}
	}
	return (NULL);
}
