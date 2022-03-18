/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:06:11 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/18 16:26:10 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo)
{
	printf("Philosopher[%d] is thinking\n", philo->philo_no);
	usleep(philo->time_to_sleep);
}

void	take_fork(t_philo *philo)
{
	int	left;
	int	right;

	left = philo->philo_no;
	right = (philo->philo_no + 1) % philo->no_of_philos;
	pthread_mutex_lock(&philo->fork[left]);
	pthread_mutex_lock(&philo->fork[right]);
	philo->status[philo->philo_no] = 'e';
	printf("philo[%d] is eating\n", philo->philo_no);
	usleep(philo->time_to_eat);
	pthread_mutex_unlock(&philo->fork[left]);
	pthread_mutex_unlock(&philo->fork[right]);
}
