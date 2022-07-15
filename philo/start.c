/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:03:02 by anovelli          #+#    #+#             */
/*   Updated: 2022/07/15 12:21:24 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.c"

void    im_hungry(t_philo *philo)
{
    pthread_mutex_lock(&philo->rules->die_mutex);
	philo->rules->die = 0;
	pthread_mutex_unlock(&philo->rules->die_mutex);
}

void	*food(void *philo)
{
    t_philo *phiiii;

    phiiii = philo;
    im_hungry(phiiii);
}

void    now_start_this(t_rules *rules)
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
}