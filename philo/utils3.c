/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 11:05:34 by anovelli          #+#    #+#             */
/*   Updated: 2022/08/10 16:40:02 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	food_helper(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->must_eat_mutex);
	philo->hungry = what_time_is_it() - philo->rules->start;
	pthread_mutex_unlock(&philo->rules->must_eat_mutex);
	philo->n_eat++;
}

size_t	get_digits(int n)
{
	size_t	i;

	i = 1;
	while (n)
	{
		n = n / 10;
		if (!n)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str_num;
	size_t		digits;
	long int	num;

	num = n;
	digits = get_digits(n);
	if (n < 0)
	{
		num *= -1;
		digits++;
	}
	str_num = (char *)malloc(sizeof(char) * (digits + 1));
	if (!str_num)
		return (NULL);
	*(str_num + digits) = 0;
	while (digits--)
	{
		*(str_num + digits) = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		*(str_num + 0) = '-';
	free (str_num);
	return (str_num);
}
