/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talk_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:05:38 by anovelli          #+#    #+#             */
/*   Updated: 2022/07/27 10:06:04 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_tell_me(t_philo *philo, int id, char *str)
{
	sem_wait(philo->rules->mess);
	printf("%lld ", what_time_is_it() - philo->rules->start);
	printf("%d %s\n", id, str);
	sem_post(philo->rules->mess);
}

void	pezzott_sleep(long long time)
{
	long long	tmp;

	tmp = what_time_is_it();
	usleep(time * 1000 - 20000);
	while (what_time_is_it() < tmp + time)
		continue ;
}

int	finish(t_philo *philo)
{
	 long long time;

	time = (what_time_is_it() - philo->rules->start - philo->last_eat);
	if (time > philo->rules->time_to_die)
	{
		sem_wait(philo->rules->mess);
		ft_tell_me(philo, philo->id, DIED);
		sem_post(philo->rules->dead);
		return (1);
	}
	if (philo->n_al_eat == philo->rules->n_eat)
	{
		sem_post(philo->rules->must_eat);
		return (1);
	}
	return (0);
}
