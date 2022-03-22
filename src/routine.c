/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:37:33 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/22 15:22:10 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = malloc(sizeof(t_philo));
	data_init((t_philo *)arg, philo);
	i = 0;
	pthread_create(philo->waiter, NULL, &monitor, (void *)philo);
	if (philo->no_times_to_eat != 0)
	{
		while (i < philo->no_times_to_eat)
		{
			thinking(philo, philo->philo_no);
			i++;
		}
	}
	else
	{
		while (1)
		{
			thinking(philo, philo->philo_no);
		}
	}
	return (NULL);
}

void	*monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if ((philo->last_meal - philo->start_time) > philo->time_to_die)
	{
		printf("dead\n");
		return (NULL);
	}
	return (NULL);
}
