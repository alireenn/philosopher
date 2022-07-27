/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:14:07 by anovelli          #+#    #+#             */
/*   Updated: 2022/07/27 11:10:18 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

int	is_digit_or_space(char c)
{
	if (c == ' ' || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	ft_check(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i != argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!is_digit_or_space(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}


long long	what_time_is_it(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

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