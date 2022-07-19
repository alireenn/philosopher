/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:55:07 by anovelli          #+#    #+#             */
/*   Updated: 2022/07/19 12:53:53 by anovelli         ###   ########.fr       */
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

int	is_over_helper(t_philo *phi, int temp, int it)
{
	pthread_mutex_lock(&phi->rules->philo_time);
	temp = what_time_is_it() - phi->rules->start - phi[it].hungry;
	pthread_mutex_unlock(&phi->rules->philo_time);
	if (temp > phi->rules->time_to_die)
	{
		ft_kill(phi);
		usleep(2000);
		ft_tell_me(&phi[it], phi[it].id, DIED);
		return (1);
	}	
}
