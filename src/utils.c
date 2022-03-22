/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:36:43 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/22 15:20:58 by clmurphy         ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	int		i;
	int		res;
	int		sign;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (sign * res);
}

void	update_meal_time(t_philo *philo)
{
	philo->last_meal = print_time();
	philo->nb_meals++;
}

void	my_usleep(int time_to)
{
	unsigned int	sleep_time;

	sleep_time = time_to * 1000;
	usleep(sleep_time);
}

long int	print_time(void)
{
	struct timeval	tv;
	long int		time_ms;

	gettimeofday(&tv, NULL);
	time_ms = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return (time_ms);
}
/* 
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
 */