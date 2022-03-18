/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:36:43 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/18 12:32:37 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

long int	print_time(void)
{
	struct timeval	tv;
	long int		time_ms;

	gettimeofday(&tv, NULL);
	time_ms = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	printf("time : %ld\n", time_ms);
	return (time_ms);
}

void	print_list(t_philo **philo)
{
	int		i;
	t_philo	*temp;
	int		n;

	n = (*philo)->no_of_philos;
	printf("n is %d\n", n);
	temp = *philo;
	i = 0;
	while (i < n)
	{
		printf("philo no is %d\n", temp->philo_no);
		printf("philo eat is %d\n", temp->time_to_eat);
		printf("philo sleep is %d\n", temp->time_to_sleep);
		temp = temp->next;
		i++;
	}
}
