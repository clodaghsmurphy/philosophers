/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:57:59 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/29 18:44:44 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	create_threads(char **av, int no_of_philos)
{
	t_param			*params;
	int				i;

	i = 0;
	params = malloc(sizeof(t_param));
	if (!params)
		return ;
	param_init(av, params);
	mutex_init(params);
	i = 0;
	while (i < no_of_philos)
	{	
		philo_init(params, i);
	 	if (i % 2 == 0)
		{
			my_usleep(params->time_to_eat * 0.9);
		}
		pthread_create(&params->philo_thread[i], NULL, \
			&routine, (void *)&params->philos[i]);		
		i++;
	}
	join_threads(params);
	end_threads(params);
}

void	join_threads(t_param *params)
{
	int	i;

	i = 0;
	while (i < params->no_of_philos)
	{
		if (pthread_join(params->philo_thread[i], NULL) != 0)
			mutex_err("Error : unable to join philo thread\n");
		if (pthread_join(*(params->philos[i].waiter), NULL) != 0)
			mutex_err("Error : unable to join waiter thread\n");
		i++;
	}
}

int	main(int ac, char **av)
{
	int				i;

	i = 1;
	if (ac < 5 || ac > 6)
	{
		printf("Wrong philo->no_of_philos of arguments! \n");
		return (0);
	}
	while (i < ac)
	{
		if (ft_atoi(av[i]) < 0)
		{
			printf("Positive philo->no_of_philoss only\n");
			return (0);
		}
		i++;
	}
	create_threads(av, ft_atoi(av[1]));
	return (0);
}
