/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:00:07 by anovelli          #+#    #+#             */
/*   Updated: 2022/07/29 09:52:00 by anovelli         ###   ########.fr       */
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

int	is_one(t_rules *rules)
{
	if (rules->n_ph == 1)
	{
		ft_tell_me(rules->philo, rules->philo[0].id, FORK);
		ft_tell_me(rules->philo, rules->philo[0].id, DIED);
		kill(rules->philo[0].pid, SIGKILL);
		return (1);
	}
	return (0);
}
