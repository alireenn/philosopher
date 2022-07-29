/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:38:57 by anovelli          #+#    #+#             */
/*   Updated: 2022/07/29 12:07:43 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	finish(t_philo *philo)
{
	long long	time;

	time = (what_time_is_it() - philo->rules->start - philo->last_eat);
	if (time > philo->rules->time_to_die)
	{
		sem_wait(philo->rules->mess);
		ft_tell_me(philo, philo->id, DIED);
		sem_post(philo->rules->dead);
		return (1);
	}
	if (philo->n_eat == philo->rules->n_to_eat)
	{
		sem_post(philo->rules->must_eat);
		return (1);
	}
	return (0);
}

void	*monitor(void *phi)
{
	t_philo		*philo;

	philo = phi;
	while (1)
	{
		if (finish(philo) == 1)
			return (NULL);
	}
	return (NULL);
}

void	*all_soreta_things(void *phi)
{
	t_philo		*philo;

	philo = phi;
	philo->last_eat = what_time_is_it() - philo->rules->start;
	pthread_create(&philo->death, NULL, monitor, philo);
	while (1)
	{
		sem_wait(philo->rules->fork);
		ft_tell_me(philo, philo->id, FORK);
		sem_wait(philo->rules->fork);
		ft_tell_me(philo, philo->id, FORK);
		ft_tell_me(philo, philo->id, EAT);
		philo->n_eat++;
		philo->last_eat = what_time_is_it() - philo->rules->start;
		pezzott_sleep(philo->rules->time_eat);
		sem_post(philo->rules->fork);
		sem_post(philo->rules->fork);
		ft_tell_me(philo, philo->id, SLEEP);
		pezzott_sleep(philo->rules->time_sleep);
		ft_tell_me(philo, philo->id, THINK);
	}
	return (NULL);
}

void	*eat63(void	*ruls)
{
	t_rules	*rules;
	int		i;

	rules = ruls;
	i = 0;
	while (i < rules->n_ph)
	{
		sem_wait(rules->must_eat);
		i++;
	}
	i = 0;
	while (i < rules->n_ph)
	{
		kill(rules->philo[i].pid, SIGKILL);
		i++;
	}
	sem_post(rules->dead);
	return (NULL);
}

void	now_start_this(t_rules *rules)
{
	int		i;

	i = 0;
	rules->start = what_time_is_it();
	if (is_one(rules) == 1)
		exit (0);
	if (rules->n_to_eat != -1)
		pthread_create(&rules->finish_eat, NULL, eat63, rules);
	while (i < rules->n_ph)
	{
		rules->philo[i].pid = fork();
		if (rules->philo[i].pid == 0)
			all_soreta_things(&rules->philo[i]);
		i++;
	}
	sem_wait(rules->dead);
	i = 0;
	while (i < rules->n_ph)
	{
		kill(rules->philo[i].pid, 9);
		i++;
	}
	exit (0);
}
