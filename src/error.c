/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:32:01 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/28 14:06:13 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_threads(t_param *params)
{
	int	i;

	i = 0;
	while (i < params->no_of_philos)
	{
		pthread_mutex_destroy(&params->fork[i]);
		pthread_mutex_destroy(params->philos[i].lock_meal_time);
		free(params->philos[i].waiter);
		free(params->philos[i].lock_meal_time);
		i++;
	}
	pthread_mutex_destroy(params->write);
	pthread_mutex_destroy(params->update_meals);
	pthread_mutex_destroy(params->end);
	free(params->philo_thread);
	free(params->write);
	free(params->end);
	free(params->update_meals);
	free(params->fork);
	free(params->philos);
	free(params);
	exit(0);
}

void	mutex_err(char	*str)
{
	printf("%s", str);
	exit(0);
}
