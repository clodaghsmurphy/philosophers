/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:32:01 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/27 20:02:59 by clmurphy         ###   ########.fr       */
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
		pthread_mutex_destroy(params->philos[i].lock_meal);
		i++;
	}
	/* pthread_mutex_destroy(params->write);
	pthread_mutex_destroy(params->update_meals);
	pthread_mutex_destroy(params->end); */
	free(params->fork);
	free(params->philos);
	exit(0);
}

void	mutex_err(char	*str)
{
	printf("%s", str);
	exit(0);
}
