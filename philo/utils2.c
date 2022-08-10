/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:55:07 by anovelli          #+#    #+#             */
/*   Updated: 2022/08/10 17:12:20 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_take_fork(t_philo *philo)
{
	if (philo->rules->n_ph == 1)
		return (1);
	pthread_mutex_lock(philo->right);
	if (check_mutex(0, philo))
		ft_tell_me(philo, philo->id, FORK);
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

int	is_over_helper(t_philo *phi, int it)
{
	long long	temp;

	pthread_mutex_lock(&phi->rules->philo_time);
	temp = what_time_is_it() - phi->rules->start - phi[it].hungry;
	pthread_mutex_unlock(&phi->rules->philo_time);
	if (temp > phi->rules->time_to_die)
	{
		ft_tell_me(phi, phi[it].id, DIED);
		im_hungry(phi);
		return (1);
	}
	return (0);
}

int	check_mutex(int n, t_philo *philo)
{
	int	temp;

	temp = 0;
	if (n == 0)
	{
		pthread_mutex_lock(&philo->rules->die_mutex);
		temp = philo->rules->die;
		pthread_mutex_unlock(&philo->rules->die_mutex);
	}
	else
	{
		pthread_mutex_lock(&philo->rules->must_eat_mutex);
		temp = philo->end;
		pthread_mutex_unlock(&philo->rules->must_eat_mutex);
	}
	return (temp);
}

void	ft_tell_me(t_philo *philo, int id, char *str)
{
	int		timeint;

	pthread_mutex_lock(&philo->rules->lock);
	timeint = what_time_is_it() - philo->rules->start;
	printf("%d %d %s\n", timeint, id, str);
	pthread_mutex_unlock(&philo->rules->lock);
}
