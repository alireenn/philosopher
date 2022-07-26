/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:38:57 by anovelli          #+#    #+#             */
/*   Updated: 2022/07/26 17:12:55 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor(void *phi)
{
	t_philo	*philo;
									//QUIIIIIIIIIII 2
	philo = phi;

}

void	*all_soreta_things(void *philo)
{
	t_philo	*phi;

	phi = philo;
	pthread_create(&phi->death, NULL, monitor, phi); 		//QUAAAAAAAAAA 1
	while (1)
	{
		sem_wait(phi->rules->fork);
		ft_tell_me(phi, phi->id, FORK);
		sem_wait(phi->rules->fork);
		ft_tell_me(phi, phi->id, FORK);
		ft_tell_me(phi, phi->id, EAT);
		phi->n_eat++ ;
		phi->last_eat = what_time_is_it() - phi->rules->start;
		pezzott_sleep(phi->rules->time_eat);
		sem_post(phi->rules->fork);
		sem_post(phi->rules->fork);
		ft_tell_me(phi, phi->id, SLEEP);
		pezzott_sleep(phi->rules->time_sleep);
		ft_tell_me(phi, phi->id, THINK);
	}
	return (NULL);
}

void	*eat63(void	*rul)
{
	t_rules	*rules;
	int		i;

	rules = rul;
	i = 0;
	while (i <= rules->n_ph)
	{
		sem_wait(rules->must_eat);
		i++;
	}
	i = 0;
	while (i <= rules->n_ph)
	{
		kill(rules->philo[i].pid, 9);
		i++;
	}
	sem_post(rules->dead);
}

void	now_start_this(t_rules *rules)
{
	int		i;
	t_philo	*philo;

	philo = rules->philo;
	rules->start = what_time_is_it();
	i = 0;
	if (rules->must_eat != -1) 
		pthread_create(rules->finish_eat, NULL, eat63, rules);
	while (i <= rules->n_ph)
	{
		philo[i].id = fork();
		if (philo[i].id == 0)
			all_soreta_things(&philo[i]);
		i++;
	}
	sem_wait(rules->dead);
}
