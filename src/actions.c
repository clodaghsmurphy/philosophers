/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:06:11 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/25 09:39:42 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	prompt(t_philo *philo, int philo_no, char *str)
{
	long int	time;

	if (philo->params->all_alive == 1 && \
	philo->params->total_meals <= philo->params->no_times_to_eat)
	{
		pthread_mutex_lock(philo->params->write);
		time = print_time() - philo->start_time;
		printf("%ld %d %s", time, philo_no + 1, str);
		pthread_mutex_unlock(philo->params->write);
	}
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
