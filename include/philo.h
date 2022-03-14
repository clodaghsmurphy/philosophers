/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:58:26 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/14 10:48:30 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include"libft.h"

/*----------------utils-------------*/
void	ft_putstr(char *str);
void	*routine(void *arg);