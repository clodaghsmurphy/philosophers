/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:57:59 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/27 20:29:19 by clmurphy         ###   ########.fr       */
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
		if (i % 2 == 1)
			my_usleep(200);
		philo_init(params, i);
		pthread_create(&params->philo_thread[i], NULL, \
			&routine, (void *)&params->philos[i]);
		i++;
	}
	i = 0;
	while (i < no_of_philos)
	{
		pthread_join(params->philo_thread[i], NULL);
		pthread_join(*(params->philos[i].waiter), NULL);
		i++;
	}
	end_threads(params);
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
