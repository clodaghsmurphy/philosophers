/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:58:26 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/30 17:16:44 by clmurphy         ###   ########.fr       */
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

struct	s_philo;
struct	s_param;

typedef struct s_philo
{
	pthread_t			*waiter;
	pthread_mutex_t		*lock_meal_time;
	int					left;
	int					right;
	int					philo_no;
	int					nb_meals;
	long int			last_meal;
	struct s_param		*params;
}	t_philo;

typedef struct s_param
{
	int					no_of_philos;
	long int			start_time;
	int					time_to_eat;
	int					time_to_die;
	int					time_to_sleep;
	int					total_meals;
	int					no_times_to_eat;
	int					all_alive;
	t_philo				*philos;
	pthread_t			*philo_thread;
	pthread_mutex_t		*fork;
	pthread_mutex_t		*end;
	pthread_mutex_t		*update_meals;
	pthread_mutex_t		*write;

}	t_param;

/*----------------utils-------------*/
int			ft_atoi(const char *str);
/*-----------------philo---------*/
void		create_threads(char **av, int no_of_philos);
void		join_threads(t_param *params);
int			check_meals(t_philo *philo, int total_meals, int ntte);
/*---------rotuine-----------*/
void		*routine(void *arg);
int			still_alive(t_param *params);
/*----------monitor----------*/
void		*monitor(void *arg);
int			check_philos(t_philo *philo);
/*-----------actions----------*/
void		dine(t_philo *philo);
void		prompt(t_philo *philo, int philo_no, char *str);
void		take_forks(t_philo	*philo);
void		is_eating(t_philo *philo);
void		sleeping_and_thinking(t_philo *philo);
/*------------init----------------*/
void		init_threads(t_philo *philo, int no_of_philos);
void		philo_init(t_param *params, int i);
void		data_init(t_philo *philo, t_philo *d);
void		param_init(char **av, t_param *params);
void		mutex_init(t_param *params);
void		param_mutex_init(t_param *param);
void		init_forks(t_param *params, int i);

/*--------------error---------------*/
void		end_threads(t_param *params);
void		mutex_err(char	*str);
/*--------------time------------*/
void		update_meal_time(t_philo *philo);
void		my_usleep(int time_to);
long int	print_time(void);

#endif