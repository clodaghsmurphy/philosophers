/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:32:01 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/23 17:25:57 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_threads(t_philo *philo)
{
	int	i;

	i = 0;
	printf("philo %d died after %d of meal\n", \
	philo->philo_no, philo->nb_meals);
	while (i < philo->no_of_philos)
	{
		pthread_mutex_destroy(&philo->fork[i]);
		i++;
	}
	pthread_mutex_destroy(philo->write);
	pthread_mutex_destroy(philo->meal_time);
	free(philo->fork);
	free(philo->write);
	free(philo->waiter);
	free(philo->meal_time);
	free(philo->data_lock);
	free(philo);
	exit(0);
}
