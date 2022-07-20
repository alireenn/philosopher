/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:03:02 by anovelli          #+#    #+#             */
/*   Updated: 2022/07/20 14:58:00 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	im_hungry(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->die_mutex);
	philo->rules->die = 0;
	pthread_mutex_unlock(&philo->rules->die_mutex);
}

void	*food(void *philo)
{
	t_philo	*phiiii;

	phiiii = philo;
	if (phiiii->id % 2 == 0)
	 	pezzott_sleep(phiiii->rules->time_eat);
	while (check_mutex(0, phiiii))
	{
		if (ft_take_fork(phiiii) == 1)
			break ;
		if (check_mutex(0, phiiii) == 1)
			ft_tell_me(phiiii, phiiii->id, EAT);
		phiiii->hungry = what_time_is_it() - phiiii->rules->start;
		phiiii->n_eat++;
		if (phiiii->n_eat == phiiii->rules->must_eat)
		{
			pthread_mutex_unlock(&phiiii->rules->die_mutex);
			phiiii->end = 1;
			pthread_mutex_unlock(&phiiii->rules->die_mutex);
		}
		ft_routine(phiiii);
	}
	return (NULL);
}

int	ft_is_over(t_philo *ph, long long temp, int i, int check)
{
	int	it;

	it = 0;
	while (it < ph->rules->n_ph)
	{
		if (is_over_helper(ph, temp, it) == 1)
			return (1);
		if (check_mutex(1, &ph[i]))
			check++;
		it++;
	}
	if (check == ph->rules->n_ph)
	{
		destroy(ph->rules);
		return (1);
	}
	return (0);
}

void	ft_loop(void *philo)
{
	t_philo	*phiiii;
	long long		tmp;
	int		i;
	int		check;

	check = 0;
	tmp = 0;
	i = 0;
	phiiii = philo;
	while (1)
	{
		if (ft_is_over(phiiii, tmp, i, check) == 1)
			break ;
	}
}

void	now_start_this(t_rules *rules)
{
	int		i;
	t_philo	*philo;

	philo = rules->philo;
	rules->start = what_time_is_it();
	i = 0;
	while (i < rules->n_ph)
	{
		pthread_create(&philo[i].thread, NULL, food, &philo[i]);
		i++;
	}
	ft_loop(philo);
	i = 0;
	while (i < rules->n_ph)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}
