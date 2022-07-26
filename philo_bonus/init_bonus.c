/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:12:30 by anovelli          #+#    #+#             */
/*   Updated: 2022/07/26 15:39:21 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_philo(t_rules *rules)
{
	int		i;

	i = 0;
	while (i <= rules->n_ph)
	{
		rules->philo[i].id = i + 1;
		rules->philo[i].rules = rules;
		rules->philo[i].n_eat = 0;
		i++;
	}
}

sem_t	*sem_in(char *message, int n)
{
	sem_t *semmy;

	semmy = sem_open(message, O_CREAT | O_EXCL, 0644, n);
	if (semmy == SEM_FAILED)
	{
		sem_unlink(message);
		return (sem_open(message, O_CREAT | O_EXCL, 0644, n));
	}
	return (semmy);
}

int	initrules(t_rules *rules)
{
	rules->mess = sem_in("message", 1);
	rules->fork = sem_in("forks", rules->n_ph);
	rules->must_eat = sem_in("must eat", 0);
	rules->dead = sem_in("dead", 1);
	rules->philo = malloc(sizeof(t_philo) * rules->n_ph);
	if (!rules->philo)
		return (0);
	return (1);
}

int	init(t_rules *rules, char *argv[], int argc)
{
	if(!ft_check(argc, argv))
		return (0);
	rules->n_ph = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_eat = ft_atoi(argv[3]);
	rules->time_sleep = ft_atoi(argv[4]);
	rules->die = 1;
	if (argc == 6)
	{
		rules->n_eat = ft_atoi(argv[5]);
		if (rules->n_eat == 0)
			return (0);
	}
	else
		rules->n_eat = -1;
	if(!initrules(rules))
		return (0);
	return (1);
}
