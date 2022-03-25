/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:32:01 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/25 12:14:01 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		printf("philo %d died after %d meals\n", \
		philo->params->philos[i].philo_no + 1, philo->params->philos[i].nb_meals);
		i++;
	}
	i = 0;
	//pthread_mutex_destroy(philo->params->write);
	//pthread_mutex_destroy(philo->lock_meal);
	while (i < philo->params->no_of_philos)
	{
		//free(&philo->params->philo_thread[i]);
		//pthread_mutex_destroy(&philo->params->fork[i]);
		i++;
	}
	//free(philo->params);
	//free(philo);
	exit(0);
}

void	mutex_err(char	*str)
{
	printf("%s", str);
	exit(0);
}
