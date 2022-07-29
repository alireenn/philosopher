/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:03:02 by anovelli          #+#    #+#             */
/*   Updated: 2022/07/29 14:05:34 by anovelli         ###   ########.fr       */
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
	t_philo	*phi;

	phi = philo;
	pthread_mutex_lock(&phi->rules->must_eat_mutex);
	phi->hungry = what_time_is_it() - phi->rules->start;
	pthread_mutex_unlock(&phi->rules->must_eat_mutex);
	if (phi->id % 2 == 0)
		pezzott_sleep(60);
	while (check_mutex(0, phi))
	{
		if (ft_take_fork(phi) == 1)
			break ;
		if (check_mutex(0, phi) == 1)
			ft_tell_me(phi, phi->id, EAT);
		food_helper(phi);
		if (phi->n_eat == phi->rules->must_eat)
		{
			pthread_mutex_lock(&phi->rules->die_mutex);
			phi->end = 1;
			pthread_mutex_unlock(&phi->rules->die_mutex);
		}
		ft_routine(phi);
	}
	return (NULL);
}

int	ft_is_over(t_philo *ph, int check)
{
	int	it;

	it = 0;
	while (it < ph->rules->n_ph)
	{
		if (is_over_helper(ph, it) == 1)
			return (1);
		if (check_mutex(1, &ph[it]))
			check++;
		it++;
	}
	if (check == ph->rules->n_ph)
	{
		ph->rules->die = 0;
		return (1);
	}
	return (0);
}

void	*ft_loop(void *philo)
{
	t_philo			*phiiii;
	int				check;

	check = 0;
	phiiii = philo;
	while (1)
	{
		if (ft_is_over(phiiii, check) == 1)
			break ;
	}
	return (NULL);
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
	destroy(philo->rules);
}
