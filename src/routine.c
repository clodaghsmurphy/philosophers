/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:37:33 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/23 14:57:50 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo			*philo;
	int				i;

	philo = malloc(sizeof(t_philo));
	philo->data_lock = malloc(sizeof(pthread_mutex_t));
	if (!philo->data_lock)
		return (NULL);
	pthread_mutex_init(philo->data_lock, NULL);
	pthread_mutex_lock(philo->data_lock);
	data_init((t_philo *)arg, philo);
	pthread_mutex_unlock(philo->data_lock);
	i = 0;
	pthread_create(philo->waiter, NULL, &monitor, (void *)philo);
	if (philo->no_times_to_eat != -1)
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
	printf("\nPhilo[%d] ate %d meals\n", philo->philo_no, philo->nb_meals);
	return (NULL);
}

void	*monitor(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if ((print_time() - philo->last_meal) > philo->time_to_die)
		{
			printf("dead because time since last meal : %ld\n", (print_time() - philo->last_meal));
			end_threads(philo);
			exit(0);
			return (NULL);
		}
	}
	return (NULL);
}
