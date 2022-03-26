/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:32:01 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/26 16:39:28 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_threads(t_param *params)
{
	int	i;

	i = 0;
/* 	while (i < 5)
	{
		pthread_mutex_lock(philo->lock_meal);
		printf("philo %d died after %d meals\n", \
		philo->params->philos[i].philo_no + 1, \
		philo->params->philos[i].nb_meals);
		i++;
		pthread_mutex_unlock(philo->lock_meal);
	}
	i = 0; */
	pthread_mutex_destroy(params->write);
	pthread_mutex_destroy(params->philos->lock_meal);
	while (i < params->no_of_philos)
	{
		//free(&philo->params->philo_thread[i]);
		pthread_mutex_destroy(&params->fork[i]);
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
