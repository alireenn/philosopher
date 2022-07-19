/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:57:35 by anovelli          #+#    #+#             */
/*   Updated: 2022/07/19 12:43:20 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - '0') * sign;
		i++;
	}
	return (res);
}

int	is_ok(int n)
{
	if (n > __INT_MAX__ || n < 0)
		return (0);
	return (1);
}

long long	what_time_is(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_tell_me(t_philo *philo, int id, char *str)
{
	pthread_mutex_lock(&philo->rules->lock);
	printf("%lld ", what_time_is() - philo->rules->start);
	printf("%d %s\n", id, str);
	pthread_mutex_unlock(&philo->rules->lock);
}

void	pezzott_sleep(long long time)
{
	long long	tmp;

	tmp = what_time_is();
	usleep(time * 1000 - 20000);
	while (what_time_is() < tmp + time)
		continue ;
}
