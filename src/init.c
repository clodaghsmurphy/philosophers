/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:38:29 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/24 13:45:22 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_param *params, int i)
{
	params->philos[i].philo_no = i;
	params->philos[i].nb_meals = 0;
	params->philos[i].start_time = print_time();
	params->philos[i].last_meal = print_time();
	params->philos[i].params = params;
	params->philos[i].right = params->philos[i].philo_no;
	params->philos[i].left = (params->philos[i].philo_no + 1) \
	% params->no_of_philos;
	params->philos[i].waiter = malloc(sizeof(pthread_t) * params->no_of_philos);
	if (!params->philos[i].waiter)
		return ;
	params->philos[i].lock_meal = malloc(sizeof(pthread_mutex_t) \
	* params->no_of_philos);
	if (!params->philos[i].lock_meal)
		return ;
	if (pthread_mutex_init(params->philos[i].lock_meal, NULL))
		mutex_err("lock meal init error\n");
}

void	param_init(char **av, t_param *params)
{
	params->no_of_philos = ft_atoi(av[1]);
	params->time_to_eat = ft_atoi(av[3]);
	params->time_to_die = ft_atoi(av[2]);
	params->time_to_sleep = ft_atoi(av[4]);
	params->all_alive = 1;
	//params->total_meals;
	if (av[5])
		params->no_times_to_eat = ft_atoi(av[5]);
	else
		params->no_times_to_eat = -1;
	params->philos = malloc(sizeof(t_philo) * params->no_of_philos);
	if (!params->philos)
		return ;
	params->philo_thread = malloc(sizeof(pthread_t) * params->no_of_philos);
	if (!params->philo_thread)
		return ;
	params->fork = malloc(sizeof(pthread_mutex_t) * params->no_of_philos);
	if (!params->fork)
		return ;
	params->write = malloc(sizeof(pthread_mutex_t) * params->no_of_philos);
	if (!params->write)
		return ;
	params->data_lock = malloc(sizeof(pthread_mutex_t) * params->no_of_philos);
	if (!params->data_lock)
		return ;
}

void	mutex_init(t_param *params)
{
	int	i;

	i = 0;
	while (i < params->no_of_philos)
	{
		if (pthread_mutex_init(&params->fork[i], NULL))
			mutex_err("fork init error\n");
		i++;
	}
}
