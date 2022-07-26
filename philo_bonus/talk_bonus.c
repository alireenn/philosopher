/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talk_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:05:38 by anovelli          #+#    #+#             */
/*   Updated: 2022/07/26 16:29:12 by anovelli         ###   ########.fr       */
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

void	pezzott_sleep(long long time)
{
	long long	tmp;

	tmp = what_time_is_it();
	usleep(time * 1000 - 20000);
	while (what_time_is_it() < tmp + time)
		continue ;
}
