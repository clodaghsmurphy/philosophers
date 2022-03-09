/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:57:59 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/09 14:20:54 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	*ft_philo(void *arg)
{
	printf("Hry\n");
}

int	main(int ac, char **av)
{
	int			i;
	int			number;
	pthread_t	philo[ft_atoi(av[1])];

	i = 0;
	number = ft_atoi(av[1]);
	if (ac < 5 || ac > 6)
	{
		ft_putstr("Wrong number of arguements! \n");
		return (0);
	}
	while (i < ac)
	{
		if (ft_atoi(av[i]) < 0)
		{
			ft_putstr("Positive numbers only\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < number)
	{
		printf("i is %d\n", i);
		pthread_create(&philo[i], NULL, &ft_philo, NULL);
		i++;
	}
	i = 0;
	while (i < number)
	{
		pthread_join(philo[i], NULL);
		i++;
	}
}
