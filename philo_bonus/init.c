/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:12:30 by anovelli          #+#    #+#             */
/*   Updated: 2022/07/25 16:50:12 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init(t_rules *rules, char *argv[])
{
	rules->n_ph = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_eat = ft_atoi(argv[3]);
	rules->time_sleep = ft_atoi(argv[4]);
	rules->die = 1;
	if (!is_ok(rules->n_ph) || !is_ok(rules->time_to_die)
		|| !is_ok(rules->time_eat) || !is_ok(rules->time_sleep))
		return (0);
	return (1);
}

void	now_start_this(t_rules *rules)
{
	int		i;
	t_philo	*philo;

	philo = rules->philo;
	rules->start = what_time_is_it();
	i = 0;
}