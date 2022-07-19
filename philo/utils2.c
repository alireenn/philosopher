/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:55:07 by anovelli          #+#    #+#             */
/*   Updated: 2022/07/19 12:46:53 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_take_fork(t_philo *philo)
{
	
}

void	ft_routine(t_philo *philo)
{
	pezzott_sleep(philo->rules->time_eat);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	if (check_mutex(0, philo))
		ft_tell_me(philo, philo->id, SLEEP);
	pezzott_sleep(philo->rules->time_sleep);
	if (check_mutex(0, philo))
		ft_tell_me(philo, philo->id, THINK);
}
