/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:22:18 by anovelli          #+#    #+#             */
/*   Updated: 2022/07/21 15:11:59 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_rules	*rules;

	if (argc != 5 && argc != 6)
		return (printf("Wrong amount of arguments\n"));
	rules = malloc (sizeof(t_rules) * ft_atoi(argv[1]));
	if (!rules)
		return (0);
	if (!init(rules, argv))
		return (printf("wrong arguments\n"));
	if (argc == 6)
	{
		(*rules).must_eat = ft_atoi(argv[5]);
		if (is_ok((*rules).must_eat) == 0)
			return (printf("Something is bad... \
			Try again with other parameters\n"));
	}
	else
		(*rules).must_eat = -1;
	now_start_this(rules);
	free (rules);
}