/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:57:59 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/18 13:33:08 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	print_time();
	philo = (t_philo *)arg;
	printf("philo[%d] is thinking\n", philo->philo_no);
	take_fork(philo);
	return (NULL);
}

void	take_fork(t_philo *philo)
{
	printf("first fork\n");
	pthread_mutex_lock(philo->fork);
	printf("aftetr ;lock\n");
	pthread_mutex_lock(philo->next->fork);
	printf("next\n");
	printf("philo[%d] is eating\n", philo->philo_no);
	sleep(3);
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(philo->next->fork);
}

// void	philo_init(char **av, t_philo *philo, int i)
// {
// 	printf("i is %d\n", i);
// 	philo->philo_no = i;
// 	philo->no_of_philos = ft_atoi(av[1]);
// 	philo->time_to_eat = ft_atoi(av[3]);
// 	philo->time_to_die = ft_atoi(av[2]);
// 	philo->time_to_sleep = ft_atoi(av[4]);
// }

void	create_threads(char **av, int no_of_philos)
{
	t_philo	*philo;
	t_philo	*temp;
	t_philo	*temp2;
	int		i;

	philo = NULL;
	temp = philo;
	temp2 = philo;
	i = 0;
	while (i < no_of_philos - 1)
	{
		ft_lstadd_back(&philo, ft_lstnew(av, i));
		printf("in looop and i is %d\n", i);
		i++;
	}
	ft_lstadd_back_last(&philo, ft_lstnew(av, i));
	i = 0;
	print_list(&philo);
	printf("hey\n");
	while (i < no_of_philos)
	{
		printf("philo no is %d\n", philo->no_of_philos);
		pthread_mutex_init(temp->fork, NULL);
		temp = temp->next;
		i++;
	}
	i = 0;
	while (i < no_of_philos)
	{
		pthread_create(temp->philo_thread, NULL, &routine, (void *)temp);
		temp = temp->next;
		i++;
	}
	i = 0;
	while (i < no_of_philos)
	{
		pthread_join(*(temp2->philo_thread), NULL);
		i++;
		temp2 = temp2->next;
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
}
