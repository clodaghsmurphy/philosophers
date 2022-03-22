/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:58:26 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/22 15:47:04 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include<unistd.h>
# include<stdio.h>
# include<pthread.h>
# include<stdlib.h>
# include<sys/time.h>
# include "philo.h"

typedef struct s_philo
{
	pthread_mutex_t		*fork;
	pthread_mutex_t		*write;
	pthread_t			*waiter;
	int					philo_no;
	int					no_of_philos;
	int					time_to_eat;
	int					time_to_die;
	int					time_to_sleep;
	int					no_times_to_eat;
	int					nb_meals;
	long int			start_time;
	long int			last_meal;
	char				status;
}	t_philo;

/*----------------utils-------------*/
void		ft_putstr(char *str);
long int	print_time(void);
void		print_list(t_philo **philo);
void		my_usleep(int time_to);
int			ft_atoi(const char *str);
void		update_meal_time(t_philo *philo);
/*-----------------philo---------*/
void		*routine(void *arg);
void		create_threads(char **av, int no_of_philos);
void		*monitor(void *arg);
/*-----------list-------------*/
void		ft_lstclear(t_philo **lst);
t_philo		*ft_lstnew(char **av, int i);
void		ft_lstadd_back(t_philo **alst, t_philo *new);
int			ft_lstsize(t_philo *lst);
void		ft_lstadd_back_last(t_philo **alst, t_philo *new);
/*-----------actions----------*/
void		thinking(t_philo *philo, int philo_no);
void		ft_sleep(t_philo *philo, int philo_no);
void		prompt(t_philo *philo, int philo_no, char *str);
void		take_fork(t_philo *philo, int philo_no);
/*------------init----------------*/
void		init_threads(t_philo *philo, int no_of_philos);
void		philo_init(char **av, t_philo *philo, int i);
void		data_init(t_philo *philo, t_philo *d);

#endif