/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:57:59 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/23 17:11:58 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	create_threads(char **av, int no_of_philos)
{
	t_philo			*philo;
	pthread_t		*philo_thread;
	int				i;

	i = 0;
	philo_thread = malloc(sizeof(pthread_t) * no_of_philos);
	if (!philo_thread)
		return ;
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return ;
	init_threads(philo, no_of_philos);
	while (i < no_of_philos)
	{
		pthread_mutex_init(&philo->fork[i], NULL);
		i++;
	}
	i = 0;
	while (i < no_of_philos)
	{
		philo_init(av, philo, i);
		philo->start_time = print_time();
		pthread_create(&philo_thread[i], NULL, &routine, (void *)philo);
		my_usleep(200);
		i++;
	}
	i = 0;
	while (i < no_of_philos)
	{
		pthread_join(philo_thread[i], NULL);
		i++;
	}
	while (i < no_of_philos)
	{
		free(&philo_thread[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	int				i;

	i = 1;
	if (ac < 5 || ac > 6)
	{
		ft_putstr("Wrong philo->no_of_philos of arguments! \n");
		return (0);
	}
	while (i < ac)
	{
		if (ft_atoi(av[i]) < 0)
		{
			ft_putstr("Positive philo->no_of_philoss only\n");
			return (0);
		}
		i++;
	}
	create_threads(av, ft_atoi(av[1]));
	return (0);
}
