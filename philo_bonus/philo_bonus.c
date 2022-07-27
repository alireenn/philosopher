/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:22:18 by anovelli          #+#    #+#             */
/*   Updated: 2022/07/27 11:38:35 by anovelli         ###   ########.fr       */
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
	if (init(rules, argv, argc) == 0)
		return (printf("wrong arguments\n"));
	init_philo(rules);
	now_start_this(rules);
	free (rules);
}