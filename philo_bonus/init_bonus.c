/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:12:30 by anovelli          #+#    #+#             */
/*   Updated: 2022/07/27 11:34:44 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

int	initrules(t_rules *rules, int argc, char **argv)
{
	rules->n_ph = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_eat = ft_atoi(argv[3]);
	rules->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		rules->n_to_eat = ft_atoi(argv[5]);
	else
		rules->n_to_eat = -1;
	rules->mess = sem_in("message", 1);
	rules->fork = sem_in("forks", rules->n_ph);
	rules->must_eat = sem_in("must_eat", 0);
	rules->dead = sem_in("dead", 0);
	rules->philo = (t_philo *) malloc (sizeof(t_philo) * rules->n_ph);
	if (rules->philo == NULL)
		return (0);
	return (1);
}

int	init(t_rules *rules, char *argv[], int argc)
{
	if(!ft_check(argc, argv))
		return (0);
	if (!rules->n_to_eat)
		rules->n_to_eat = -1;
	if(!initrules(rules, argc, argv))
		return (0);
	return (1);
}
