/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:03:02 by anovelli          #+#    #+#             */
/*   Updated: 2022/07/19 12:46:12 by anovelli         ###   ########.fr       */
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
	im_hungry(phiiii);
	if (phiiii->id % 2 == 0)
		pezzott_sleep(phiiii->rules->time_eat);
	while (check_mutex(0, phiiii))
	{
		if (ft_take_fork(phiiii) == 1)
			break ;
		if (check_mutex(0, phiiii) == 1)
			ft_tell_me(phiiii, phiiii->id, EAT);
		phiiii->n_eat++;
		if (phiiii->n_eat == phiiii->rules->must_eat)
		{
			pthread_mutex_unlock(&phiiii->rules->die_mutex);
			phiiii->end = 1;
			pthread_mutex_unlock(&phiiii->rules->die_mutex);
		}
		im_hungry(phiiii);
		ft_routine(phiiii);
	}
}

int	ft_is_over(t_philo *ph, int temp, int i, int check)
{
	int	it;
	int	check;

	it = 0;
	check = 0;
	while (it < ph->rules->n_ph)
	{
		pthread_mutex_lock(&ph->rules->philo_time);
		temp = what_time_is_it() - ph->rules->start - ph[it].hungry;
		pthread_mutex_unlock(&ph->rules->philo_time);
		if (temp > ph->rules->time_to_die)
		{
			ft_kill(ph);
			usleep(2000);
			ft_tell_me(&ph[i], ph[i].id, DIED);
			return (1);
		}
		if (check_mutex(1, &ph[i]))
			check++;
		i++;
	}
	if (check == ph->rules->n_ph)
	{
		ft_kill(ph);
		return (1);
	}
	return (0);
}

void	ft_loop(void *philo)
{
	t_philo	*phiiii;
	int		tmp;
	int		i;
	int		see;

	tmp = 0;
	i = 0;
	see = 0;
	phiiii = philo;
	while (1)
	{
		if (ft_is_over(phiiii, tmp, i, see) == 1)
			break ;
	}
}

void	now_start_this(t_rules *rules)
{
	int		i;
	t_philo	*philo;

	philo = rules->philo;
	rules->start = ft_time();
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
	destroy(rules);
}
