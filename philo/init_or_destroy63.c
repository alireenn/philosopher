/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_or_destroy63.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:12:29 by anovelli          #+#    #+#             */
/*   Updated: 2022/08/11 13:37:18 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	mutex_init(t_rules *rules)
{
	int	i;
	int	ph;

	ph = rules->n_ph;
	pthread_mutex_init(&rules->lock, NULL);
	pthread_mutex_init(&rules->die_mutex, NULL);
	pthread_mutex_init(&rules->must_eat_mutex, NULL);
	pthread_mutex_init(&rules->philo_time, NULL);
	rules->forks = (pthread_mutex_t *)malloc (sizeof(pthread_mutex_t) * ph);
	if (rules->forks == NULL)
		return (0);
	i = 0;
	while (i < rules->n_ph)
	{
		pthread_mutex_init(&rules->forks[i], NULL);
		i++;
	}
	init_philo(rules);
	return (1);
}

int	is_neg(t_rules *rules)
{
	if (rules->n_ph <= 0
		|| rules->time_to_die <= 0
		|| rules->time_eat <= 0
		|| rules->time_sleep <= 0)
		return (0);
	return (1);
}

int	init(t_rules *rules, char *argv[], int argc)
{
	if (!ft_check(argc, argv))
		return (0);
	rules->n_ph = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_eat = ft_atoi(argv[3]);
	rules->time_sleep = ft_atoi(argv[4]);
	rules->die = 1;
	rules->philo = (t_philo *) malloc (sizeof(t_philo) * rules->n_ph);
	if (rules->philo == NULL)
		return (0);
	if (!is_neg(rules))
		return (0);
	if (mutex_init(rules))
		return (1);
	return (0);
}

void	init_philo(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->n_ph)
	{
		rules->philo[i].id = i + 1;
		rules->philo[i].n_eat = 0;
		rules->philo[i].end = 0;
		rules->philo[i].rules = rules;
		rules->philo[i].left = &rules->forks[i];
		rules->philo[i].right = &rules->forks[i + 1];
		if (i == rules->n_ph - 1)
			rules->philo[i].right = &rules->forks[0];
		i++;
	}
}

void	destroy(t_rules *rules)
{
	int		i;
	t_philo	*philo;

	philo = rules->philo;
	i = 0;
	while (i < rules->n_ph)
	{
		pthread_mutex_destroy(&rules->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&rules->lock);
	pthread_mutex_destroy(&rules->die_mutex);
	pthread_mutex_destroy(&rules->must_eat_mutex);
	pthread_mutex_destroy(&rules->philo_time);
	free(philo);
	free(rules->forks);
}
