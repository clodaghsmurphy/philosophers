/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:37:33 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/30 16:12:30 by clmurphy         ###   ########.fr       */
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
			return (NULL);
		dine(philo);
	}
	
	return (NULL);
}

int	still_alive(t_param *params)
{
	pthread_mutex_lock(params->update_meals);
	pthread_mutex_lock(params->end);
	if (params->all_alive == -1 || \
	(params->total_meals >= params->no_of_philos \
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
