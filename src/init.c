/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:38:29 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/22 15:14:22 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(char **av, t_philo *philo, int i)
{
	philo->philo_no = i;
	philo->no_of_philos = ft_atoi(av[1]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->no_times_to_eat = ft_atoi(av[5]);
	else
		philo->no_times_to_eat = -1;
}

void	init_threads(t_philo *philo, int no_of_philos)
{
	philo->fork = malloc(sizeof(pthread_mutex_t) * no_of_philos);
	if (philo->fork == NULL)
		return ;
	philo->write = malloc(sizeof(pthread_mutex_t));
	if (philo->write == NULL)
		return ;
}

void	data_init(t_philo *philo, t_philo *d)
{
	d->philo_no = philo->philo_no;
	d->no_of_philos = philo->no_of_philos;
	d->start_time = philo->start_time;
	d->time_to_die = philo->time_to_die;
	d->time_to_eat = philo->time_to_eat;
	d->time_to_sleep = philo->time_to_sleep;
	d->last_meal = 0;
	d->no_times_to_eat = philo->no_times_to_eat;
	d->waiter = malloc(sizeof(pthread_t));
	if (!d->waiter)
		return ;
	d->fork = philo->fork;
	d->write = philo->write;
	d->status = 't';
	d->no_times_to_eat = philo->no_times_to_eat;
}
