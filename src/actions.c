/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:06:11 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/26 17:12:20 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	prompt(t_philo *philo, int philo_no, char *str)
{
	long int	time;

	pthread_mutex_lock(philo->params->write);
	pthread_mutex_lock(philo->params->end);
	if (philo->params->all_alive != -1)
	{
		pthread_mutex_unlock(philo->params->end);
		time = print_time() - philo->start_time;
		printf("%ld %d %s", time, philo_no + 1, str);
		if (str[0] != 'D')
			pthread_mutex_unlock(philo->params->write);
		if (str[0] != 'F')
			pthread_mutex_unlock(philo->params->write);
	}
	pthread_mutex_unlock(philo->params->end);
}

void	eat_sleep_think(t_philo *philo, int philo_no)
{
	pthread_mutex_lock(&philo->params->fork[philo->right]);
	prompt(philo, philo_no, "has taken a fork\n");
	pthread_mutex_lock(&philo->params->fork[philo->left]);
	prompt(philo, philo_no, "has taken a fork\n");
	prompt(philo, philo_no, "is eating\n");
	pthread_mutex_lock(philo->lock_meal);
	update_meal_time(philo);
	pthread_mutex_unlock(philo->lock_meal);
	my_usleep(philo->params->time_to_eat);
	pthread_mutex_unlock(&philo->params->fork[philo->right]);
	pthread_mutex_unlock(&philo->params->fork[philo->left]);
	prompt(philo, philo_no, "is sleeping\n");
	my_usleep(philo->params->time_to_sleep);
	prompt(philo, philo_no, "is thinking\n");
}

void	update_meal_time(t_philo *philo)
{
	pthread_mutex_lock(philo->params->update_meals);
	philo->last_meal = print_time();
	philo->nb_meals++;
	if (philo->nb_meals == philo->params->no_of_philos)
		philo->params->total_meals++;
	printf("philo no meals %d\n", philo->nb_meals);
	pthread_mutex_unlock(philo->params->update_meals);
	usleep(100);
}
