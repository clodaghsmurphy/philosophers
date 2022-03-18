/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:58:26 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/18 16:09:45 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include<unistd.h>
# include<stdio.h>
# include<pthread.h>
# include<stdlib.h>
# include<sys/time.h>
# include"libft.h"
# include "philo.h"

typedef struct s_philo
{
	pthread_mutex_t	*fork;
	int				philo_no;
	int				no_of_philos;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	char			*status;
}	t_philo;

/*----------------utils-------------*/
void		ft_putstr(char *str);
long int	print_time(void);
void		print_list(t_philo **philo);
/*-----------------philo---------*/
void		*routine(void *arg);
void		create_threads(char **av, int no_of_philos);
void		philo_init(char **av, t_philo *philo, int i);
void		take_fork(t_philo *philo);
/*-----------list-------------*/
void		ft_lstclear(t_philo **lst);
t_philo		*ft_lstnew(char **av, int i);
void		ft_lstadd_back(t_philo **alst, t_philo *new);
int			ft_lstsize(t_philo *lst);
void		ft_lstadd_back_last(t_philo **alst, t_philo *new);
/*-----------actions----------*/
void	thinking(t_philo *philo);

#endif