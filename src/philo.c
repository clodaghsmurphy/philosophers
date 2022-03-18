/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:57:59 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/18 16:18:49 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;
	int		i;

	i = 0;
	print_time();
	philo = (t_philo *)arg;
	while (i < philo->no_of_philos)
	{
		thinking(philo);
		take_fork(philo);
		i++;
	}
	return (NULL);
}

void	philo_init(char **av, t_philo *philo, int i)
{
	philo->status[i] = 't';
	philo->philo_no = i;
	philo->no_of_philos = ft_atoi(av[1]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_sleep = ft_atoi(av[4]);
}

void	create_threads(char **av, int no_of_philos)
{
	t_philo			*philo;
	pthread_t		*philo_thread;
	pthread_mutex_t	*fork;
	int				i;

	i = 0;
	philo = malloc(sizeof(t_philo));
	philo_thread = malloc(sizeof(pthread_t) * no_of_philos);
	if (!philo_thread)
		return ;
	fork = malloc(sizeof(pthread_mutex_t) * no_of_philos);
	if (!fork)
		return ;
	philo->status = malloc(sizeof(char *) * no_of_philos);
	if (!philo->status)
		return ;
	while (i < no_of_philos)
	{
		pthread_mutex_init(&fork[i], NULL);
		i++;
	}
	philo->fork = fork;
	i = 0;
	while (i < no_of_philos)
	{
		philo_init(av, philo, i);
		pthread_create(&philo_thread[i], NULL, &routine, (void *)philo);
		i++;
	}
	i = 0;
	while (i < no_of_philos)
	{
		pthread_join(philo_thread[i], NULL);
		i++;
	}
}

int	main(int ac, char **av)
{
	int				i;

	i = 0;
	if (ac < 5 || ac > 6)
	{
		ft_putstr("Wrong philo->no_of_philos of arguements! \n");
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
