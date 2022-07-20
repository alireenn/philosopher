/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:55:07 by anovelli          #+#    #+#             */
/*   Updated: 2022/07/20 14:57:47 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right);
	if (check_mutex(0, philo))
		ft_tell_me(philo, philo->id, FORK);
	if (philo->rules->n_ph == 1)
		return (1);
	pthread_mutex_lock(philo->left);
	if (check_mutex(0, philo))
		ft_tell_me(philo, philo->id, FORK);
	return (0);
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

int	is_over_helper(t_philo *phi, long long temp, int it)
{
	pthread_mutex_lock(&phi->rules->philo_time);
	temp = what_time_is_it() - phi->rules->start - phi[it].hungry;
	pthread_mutex_unlock(&phi->rules->philo_time);
	if (temp > phi->rules->time_to_die)
	{
		ft_tell_me(&phi[it], phi[it].id, DIED);
		im_hungry(phi);
		destroy(phi->rules);
		return (1);
	}
	return (0);
}

int	check_mutex(int n, t_philo *phiii)
{
	int	temp;

	temp = 0;
	if (n == 0)
	{
		pthread_mutex_lock(&phiii->rules->die_mutex);
		temp = phiii->rules->die;
		pthread_mutex_unlock(&phiii->rules->die_mutex);
	}
	else if (n == 1)
	{
		pthread_mutex_lock(&phiii->rules->must_eat_mutex);
		temp = phiii->end;
		pthread_mutex_unlock(&phiii->rules->must_eat_mutex);
	}
	return (temp);
}
