/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:47:25 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/18 13:29:57 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_lstnew(char **av, int i)
{
	t_philo	*new_node;

	new_node = (t_philo *)malloc(sizeof(t_philo));
	if (!new_node)
		return (NULL);
	new_node->fork = malloc(sizeof(		pthread_mutex_init(temp->fork, NULL););
	new_node->philo_thread = malloc(sizeof(new_node->philo_thread));
	new_node->philo_no = i;
	new_node->no_of_philos = ft_atoi(av[1]) + i;
	new_node->time_to_eat = ft_atoi(av[3]) + i;
	new_node->time_to_die = ft_atoi(av[2]) + i;
	new_node->time_to_sleep = ft_atoi(av[4]) + i;
	new_node ->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_philo **alst, t_philo *new)
{
	t_philo	*last;

	last = *alst;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	while (last ->next != NULL)
		last = last ->next;
	last->next = new;
}

void	ft_lstadd_back_last(t_philo **alst, t_philo *new)
{
	t_philo	*last;

	last = *alst;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	while (last ->next != NULL)
		last = last ->next;
	last->next = *alst;
}

void	ft_lstclear(t_philo **lst)
{
	t_philo	*temp;

	temp = *lst;
	while (temp != NULL)
	{
		temp = temp ->next;
		free(*lst);
		*lst = temp;
	}
}

int	ft_lstsize(t_philo *lst)
{
	unsigned int	i;

	i = 1;
	if (lst == 0)
		return (0);
	while (lst ->next != NULL)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}
