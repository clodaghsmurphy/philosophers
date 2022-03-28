/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:06:11 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/28 13:59:41 by clmurphy         ###   ########.fr       */
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
		time = print_time() - philo->start_time;
		printf("%ld %d %s", time, philo_no + 1, str);
	}
	pthread_mutex_unlock(philo->params->end);
	pthread_mutex_unlock(philo->params->write);
}

void	dine(t_philo *philo)
{
	take_forks(philo);
	is_eating(philo);
	sleeping_and_thinking(philo);
}

void	take_forks(t_philo	*philo)
{
	pthread_mutex_lock(&philo->params->fork[philo->right]);
	prompt(philo, philo->philo_no, "has taken a fork\n");
	pthread_mutex_lock(&philo->params->fork[philo->left]);
	prompt(philo, philo->philo_no, "has taken a fork\n");
}

void	is_eating(t_philo *philo)
{
	prompt(philo, philo->philo_no, "is eating\n");
	pthread_mutex_lock(philo->params->update_meals);
	pthread_mutex_lock(philo->lock_meal_time);
	update_meal_time(philo);
	my_usleep(philo->params->time_to_eat);
	pthread_mutex_unlock(&philo->params->fork[philo->right]);
	pthread_mutex_unlock(&philo->params->fork[philo->left]);
}

void	sleeping_and_thinking(t_philo *philo)
{
	prompt(philo, philo->philo_no, "is sleeping\n");
	my_usleep(philo->params->time_to_sleep);
	prompt(philo, philo->philo_no, "is thinking\n");
}
